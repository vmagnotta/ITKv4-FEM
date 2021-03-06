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
#include "itkImage.h"
#include "itkNeighborhoodConnectedImageFilter.h"

#ifdef CABLE_CONFIGURATION
#include "itkCSwigMacros.h"
#include "itkCSwigImages.h"

//=================================
//THIS FILE GENERATED WITH MakeConsistentWrappedClasses.sh
//=================================
namespace _cable_
{
  const char* const group = ITK_WRAP_GROUP(itkNeighborhoodConnectedImageFilter);
  namespace wrappers
  {
    //===========2D Wrapped Filters==============
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::F2 , image::F2 , itkNeighborhoodConnectedImageFilterF2F2  );
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::D2 , image::D2 , itkNeighborhoodConnectedImageFilterD2D2  );
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::UC2, image::UC2, itkNeighborhoodConnectedImageFilterUC2UC2);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::US2, image::US2, itkNeighborhoodConnectedImageFilterUS2US2);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::UI2, image::UI2, itkNeighborhoodConnectedImageFilterUI2UI2);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SC2, image::SC2, itkNeighborhoodConnectedImageFilterSC2SC2);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SS2, image::SS2, itkNeighborhoodConnectedImageFilterSS2SS2);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SI2, image::SI2, itkNeighborhoodConnectedImageFilterSI2SI2);

    //===========3D Wrapped Filters==============
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::F3 , image::F3 , itkNeighborhoodConnectedImageFilterF3F3  );
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::D3 , image::D3 , itkNeighborhoodConnectedImageFilterD3D3  );
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::UC3, image::UC3, itkNeighborhoodConnectedImageFilterUC3UC3);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::US3, image::US3, itkNeighborhoodConnectedImageFilterUS3US3);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::UI3, image::UI3, itkNeighborhoodConnectedImageFilterUI3UI3);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SC3, image::SC3, itkNeighborhoodConnectedImageFilterSC3SC3);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SS3, image::SS3, itkNeighborhoodConnectedImageFilterSS3SS3);
    ITK_WRAP_OBJECT2(NeighborhoodConnectedImageFilter, image::SI3, image::SI3, itkNeighborhoodConnectedImageFilterSI3SI3);
  }
}
#endif
