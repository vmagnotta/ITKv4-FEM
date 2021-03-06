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
#ifndef __itkVectorThresholdSegmentationLevelSetImageFilter_txx
#define __itkVectorThresholdSegmentationLevelSetImageFilter_txx

#include "itkVectorThresholdSegmentationLevelSetImageFilter.h"

namespace itk
{
template< class TInputImage, class TFeatureImage, class TOutputType >
VectorThresholdSegmentationLevelSetImageFilter< TInputImage, TFeatureImage, TOutputType >
::VectorThresholdSegmentationLevelSetImageFilter(void)
{
  m_ThresholdFunction = ThresholdFunctionType::New();
  m_ThresholdFunction->SetThreshold(0);

  this->SetSegmentationFunction(m_ThresholdFunction);
}

template< class TInputImage, class TFeatureImage, class TOutputType >
void
VectorThresholdSegmentationLevelSetImageFilter< TInputImage, TFeatureImage, TOutputType >
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
  os << "ThresholdFunction: " << m_ThresholdFunction;
}
} // end namespace itk

#endif
