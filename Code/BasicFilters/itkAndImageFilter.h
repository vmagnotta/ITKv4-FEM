/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkAndImageFilter_h
#define __itkAndImageFilter_h

#include "itkBinaryFunctorImageFilter.h"
#include "itkNumericTraits.h"

namespace itk
{
/** \class AndImageFilter
 * \brief Implements the AND logical operator pixel-wise between two images.
 *
 * This class is parametrized over the types of the two
 * input images and the type of the output image.
 * Numeric conversions (castings) are done by the C++ defaults.
 *
 * Since the logical AND operation is only defined in C++ for integer
 * types, the images passed to this filter must comply with the requirement
 * of using integer pixel type.
 *
 * The total operation over one pixel will be
 *
 *  output_pixel = static_cast<OutputPixelType>( input1_pixel & input2_pixel )
 *
 * Where "&" is the boolean AND operator in C++.
 *
 * \ingroup IntensityImageFilters  Multithreaded
 */
namespace Functor
{
template< class TInput1, class TInput2 = TInput1, class TOutput = TInput1 >
class AND
{
public:
  AND() {}
  ~AND() {}
  bool operator!=(const AND &) const
  {
    return false;
  }

  bool operator==(const AND & other) const
  {
    return !( *this != other );
  }

  inline TOutput operator()(const TInput1 & A, const TInput2 & B) const
  {
    return static_cast< TOutput >( A & B );
  }
};
}
template< class TInputImage1, class TInputImage2 = TInputImage1, class TOutputImage = TInputImage1 >
class ITK_EXPORT AndImageFilter:
  public
  BinaryFunctorImageFilter< TInputImage1, TInputImage2, TOutputImage,
                            Functor::AND<
                              typename TInputImage1::PixelType,
                              typename TInputImage2::PixelType,
                              typename TOutputImage::PixelType >   >

{
public:
  /** Standard class typedefs. */
  typedef AndImageFilter Self;
  typedef BinaryFunctorImageFilter< TInputImage1, TInputImage2, TOutputImage,
                                    Functor::AND<
                                      typename TInputImage1::PixelType,
                                      typename TInputImage2::PixelType,
                                      typename TOutputImage::PixelType > > Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Runtime information support. */
  itkTypeMacro(AndImageFilter,
               BinaryFunctorImageFilter);

#ifdef ITK_USE_CONCEPT_CHECKING
  /** Begin concept checking */
  itkConceptMacro( Input1Input2OutputLogicalOperatorsCheck,
                   ( Concept::LogicalOperators< typename TInputImage1::PixelType,
                                                typename TInputImage2::PixelType,
                                                typename TOutputImage::PixelType > ) );
  /** End concept checking */
#endif
protected:
  AndImageFilter() {}
  virtual ~AndImageFilter() {}
private:
  AndImageFilter(const Self &); //purposely not implemented
  void operator=(const Self &); //purposely not implemented
};
} // end namespace itk

#endif
