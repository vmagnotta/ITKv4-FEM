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
#ifndef __itkFFTWCommon_h
#define __itkFFTWCommon_h

#if defined( USE_FFTWF ) || defined( USE_FFTWD )
#include "fftw3.h"
#endif

namespace itk
{
namespace fftw
{
/**
 * \class Interface
 * \brief Wrapper for FFTW API
 */
template< typename TPixel >
class Proxy
{
  // empty -- only double and float specializations work
protected:
  Proxy() {}
  ~Proxy() {}
};

#if defined( USE_FFTWF )

template< >
class Proxy< float >
{
public:
  typedef float         PixelType;
  typedef fftwf_complex ComplexType;
  typedef fftwf_plan    PlanType;

  static PlanType Plan_dft_c2r_1d(int n,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_c2r_1d(n, in, out, flags);
  }

  static PlanType Plan_dft_c2r_2d(int nx,
                                  int ny,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_c2r_2d(nx, ny, in, out, flags);
  }

  static PlanType Plan_dft_c2r_3d(int nx,
                                  int ny,
                                  int nz,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_c2r_3d(nx, ny, nz, in, out, flags);
  }

  static PlanType Plan_dft_c2r(int rank,
                               const int *n,
                               ComplexType *in,
                               PixelType *out,
                               unsigned flags)
  {
    return fftwf_plan_dft_c2r(rank, n, in, out, flags);
  }

  static PlanType Plan_dft_r2c_1d(int n,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_r2c_1d(n, in, out, flags);
  }

  static PlanType Plan_dft_r2c_2d(int nx,
                                  int ny,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_r2c_2d(nx, ny, in, out, flags);
  }

  static PlanType Plan_dft_r2c_3d(int nx,
                                  int ny,
                                  int nz,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftwf_plan_dft_r2c_3d(nx, ny, nz, in, out, flags);
  }

  static PlanType Plan_dft_r2c(int rank,
                               const int *n,
                               PixelType *in,
                               ComplexType *out,
                               unsigned flags)
  {
    return fftwf_plan_dft_r2c(rank, n, in, out, flags);
  }

  static void Execute(PlanType p)
  {
    fftwf_execute(p);
  }

  static void DestroyPlan(PlanType p)
  {
    fftwf_destroy_plan(p);
  }
};
#endif // USE_FFTWF
#if defined( USE_FFTWD )
template< >
class Proxy< double >
{
public:
  typedef double       PixelType;
  typedef fftw_complex ComplexType;
  typedef fftw_plan    PlanType;

  static PlanType Plan_dft_c2r_1d(int n,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_c2r_1d(n, in, out, flags);
  }

  static PlanType Plan_dft_c2r_2d(int nx,
                                  int ny,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_c2r_2d(nx, ny, in, out, flags);
  }

  static PlanType Plan_dft_c2r_3d(int nx,
                                  int ny,
                                  int nz,
                                  ComplexType *in,
                                  PixelType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_c2r_3d(nx, ny, nz, in, out, flags);
  }

  static PlanType Plan_dft_c2r(int rank,
                               const int *n,
                               ComplexType *in,
                               PixelType *out,
                               unsigned flags)
  {
    return fftw_plan_dft_c2r(rank, n, in, out, flags);
  }

  static PlanType Plan_dft_r2c_1d(int n,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_r2c_1d(n, in, out, flags);
  }

  static PlanType Plan_dft_r2c_2d(int nx,
                                  int ny,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_r2c_2d(nx, ny, in, out, flags);
  }

  static PlanType Plan_dft_r2c_3d(int nx,
                                  int ny,
                                  int nz,
                                  PixelType *in,
                                  ComplexType *out,
                                  unsigned flags)
  {
    return fftw_plan_dft_r2c_3d(nx, ny, nz, in, out, flags);
  }

  static PlanType Plan_dft_r2c(int rank,
                               const int *n,
                               PixelType *in,
                               ComplexType *out,
                               unsigned flags)
  {
    return fftw_plan_dft_r2c(rank, n, in, out, flags);
  }

  static void Execute(PlanType p)
  {
    fftw_execute(p);
  }

  static void DestroyPlan(PlanType p)
  {
    fftw_destroy_plan(p);
  }
};
#endif
}
}
#endif
