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
#ifndef __itkAcosImageAdaptor_h
#define __itkAcosImageAdaptor_h

#include <itkImageAdaptor.h>
#include "vnl/vnl_math.h"

namespace itk
{
namespace Accessor
{
/** \class AcosPixelAccessor
 * \brief Give access to the vcl_acos() function of a value
 *
 * AcosPixelAccessor is templated over an internal type and an
 * external type representation. This class cast the input
 * applies the function to it and cast the result according
 * to the types defined as template parameters
 *
 * \ingroup ImageAdaptors */

template< class TInternalType, class TExternalType >
class ITK_EXPORT AcosPixelAccessor
{
public:

  /** External typedef. It defines the external aspect
   * that this class will exhibit. */
  typedef TExternalType ExternalType;

  /** Internal typedef. It defines the internal real
   * representation of data. */
  typedef TInternalType InternalType;

  static inline void Set(TInternalType & output, const TExternalType & input)
  { output = (TInternalType)vcl_acos( (double)input ); }

  static inline TExternalType Get(const TInternalType & input)
  { return (TExternalType)vcl_acos( (double)input ); }
};
} // end namespace Accessor

/** \class AcosImageAdaptor
 * \brief Presents an image as being composed of the vcl_acos() of its pixels
 *
 * Additional casting is performed according to the input and output image
 * types following C++ default casting rules.
 *
 * \ingroup ImageAdaptors */
template< class TImage, class TOutputPixelType >
class ITK_EXPORT AcosImageAdaptor:public
  ImageAdaptor< TImage, Accessor::AcosPixelAccessor<
                  typename TImage::PixelType,
                  TOutputPixelType > >
{
public:
  /** Standard class typedefs. */
  typedef AcosImageAdaptor Self;
  typedef ImageAdaptor< TImage, Accessor::AcosPixelAccessor<
                          typename TImage::PixelType,
                          TOutputPixelType > >             Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(AcosImageAdaptor, ImageAdaptor);
protected:
  AcosImageAdaptor() {}
  virtual ~AcosImageAdaptor() {}
private:
  AcosImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);   //purposely not implemented
};
} // end namespace itk

#endif
