#include "itkAnisotropicFourthOrderLevelSetImageFilter.h"
#include "itkImage.h"
#include <iostream>

int itkAnisotropicFourthOrderLevelSetImageFilterTest(int, char* [] )
{
  typedef itk::Image<float, 2> ImageType;
  typedef ImageType::IndexType IndexType;
  
  ImageType::Pointer im_init = ImageType::New();
  
  ImageType::RegionType r;
  ImageType::SizeType   sz = {{128, 128}};
  ImageType::IndexType  idx = {{0,0}};
  r.SetSize(sz);
  r.SetIndex(idx);

  im_init->SetLargestPossibleRegion(r);
  im_init->SetBufferedRegion(r);
  im_init->SetRequestedRegion(r);
  im_init->Allocate();

  IndexType index;

  for ( index[0]=0; index[0] < 128; index[0]++ )
    for ( index[1]=0; index[1] < 128; index[1]++ )
      {
      if ( (index[0]>=32) && (index[0]<=96) &&
           (index[1]>=32) && (index[1]<=96) )
        {
        im_init->SetPixel (index, static_cast<float>(-1));
        
        }
      else
        {
        im_init->SetPixel (index, static_cast<float>(1));
        }
      }
  
  typedef itk::AnisotropicFourthOrderLevelSetImageFilter<ImageType,
    ImageType> FilterType;
  FilterType::Pointer filter = FilterType::New();
  filter->SetMaxFilterIteration (150);
  filter->SetNormalProcessConductance(0.5);
                                      
  filter->SetInput(im_init);
  std::cout<<"max iteration = "<<(filter->GetMaxFilterIteration())<<"\n";
  std::cout<<"Starting processing.\n";
  filter->Update();
  filter->Print(std::cout);
  std::cout<<"Passed.\n";
  return 0;
}
