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
#ifndef __itkRGBToVectorImageAdaptor_h
#define __itkRGBToVectorImageAdaptor_h

#include "itkImageAdaptor.h"
#include "itkRGBToVectorPixelAccessor.h"

namespace itk
{
/** \class RGBToVectorImageAdaptor
 * \brief Presents an image of pixel type RGBPixel as being and image of
 * Vectors.
 *
 * \ingroup ImageAdaptors
 *
 */
template< class TImage >
class ITK_EXPORT RGBToVectorImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::RGBToVectorPixelAccessor<
                  typename TImage::PixelType::ComponentType
                  > >
{
public:
  /** Standard class typedefs. */
  typedef RGBToVectorImageAdaptor Self;
  typedef ImageAdaptor< TImage,
                        Accessor::RGBToVectorPixelAccessor<
                          typename TImage::PixelType::ComponentType
                          >  > Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(RGBToVectorImageAdaptor, ImageAdaptor);

  /** PixelContainer typedef support. Used to construct a container for
   * the pixel data. */
  typedef typename Superclass::PixelContainer             PixelContainer;
  typedef typename Superclass::PixelContainerPointer      PixelContainerPointer;
  typedef typename Superclass::PixelContainerConstPointer PixelContainerConstPointer;
protected:
  RGBToVectorImageAdaptor() {}
  virtual ~RGBToVectorImageAdaptor() {}
private:
  RGBToVectorImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);          //purposely not implemented
};
} // end namespace itk

#endif
