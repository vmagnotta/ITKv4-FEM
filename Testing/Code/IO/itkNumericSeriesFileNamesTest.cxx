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
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif
#include "itkNumericSeriesFileNames.h"

int itkNumericSeriesFileNamesTest(int, char* [])
{

  itk::NumericSeriesFileNames::Pointer fit = itk::NumericSeriesFileNames::New();
  fit->SetStartIndex(10);
  fit->SetEndIndex(20);
  fit->SetIncrementIndex(2);
  fit->SetSeriesFormat ("foo.%03d.png");

  std::vector<std::string> names = fit->GetFileNames();
  std::vector<std::string>::iterator nit;

  for (nit = names.begin();
       nit != names.end();
       nit++)
    {
    std::cout << "File: " << (*nit).c_str() << std::endl;
    }

  std::cout << fit;

  return EXIT_SUCCESS;

}
