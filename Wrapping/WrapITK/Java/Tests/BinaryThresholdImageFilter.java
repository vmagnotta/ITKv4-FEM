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

/**
 *  Example on the use of the BinaryThresholdImageFilter
 *
 */

import InsightToolkit.*;

public class BinaryThresholdImageFilter
{
  public static void main( String argv[] )
  {
    System.out.println("BinaryThresholdImageFilter Example");

    itkImageFileReaderIUS2_Pointer reader = itkImageFileReaderIUS2.itkImageFileReaderIUS2_New();
    itkImageFileWriterIUS2_Pointer writer = itkImageFileWriterIUS2.itkImageFileWriterIUS2_New();

    itkBinaryThresholdImageFilterIUS2IUS2_Pointer filter = itkBinaryThresholdImageFilterIUS2IUS2.itkBinaryThresholdImageFilterIUS2IUS2_New();

    filter.SetInput( reader.GetOutput() );
    writer.SetInput( filter.GetOutput() );

    reader.SetFileName( argv[0] );
    writer.SetFileName( argv[1] );

    filter.SetLowerThreshold(  Integer.parseInt( argv[2] )  );
    filter.SetUpperThreshold(  Integer.parseInt( argv[3] )  );

    filter.SetOutsideValue( Integer.parseInt( argv[4] )  );
    filter.SetInsideValue(  Integer.parseInt( argv[5] )  );

    writer.Update();
  }

}


