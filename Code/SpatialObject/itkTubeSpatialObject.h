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
#ifndef __itkTubeSpatialObject_h
#define __itkTubeSpatialObject_h

#include <list>

#include "itkPointBasedSpatialObject.h"
#include "itkTubeSpatialObjectPoint.h"

namespace itk
{
/**
 * \class TubeSpatialObject
 * \brief Representation of a tube based on the spatial object classes.
 *
 * The tube is basically defined by a set of points. Each tube can
 * be connected to a tube network, by using the AddSpatialObject() methods
 * of a TubeSpatialObject Object.
 * A tube is also identified by an id number when connected to a network.
 *
 * \sa TubeSpatialObjectPoint
 */

template< unsigned int TDimension = 3,
          typename TTubePointType = TubeSpatialObjectPoint< TDimension > >
class ITK_EXPORT TubeSpatialObject:
  public PointBasedSpatialObject< TDimension >
{
public:

  typedef TubeSpatialObject                           Self;
  typedef PointBasedSpatialObject< TDimension >       Superclass;
  typedef SmartPointer< Self >                        Pointer;
  typedef SmartPointer< const Self >                  ConstPointer;
  typedef double                                      ScalarType;
  typedef TTubePointType                              TubePointType;
  typedef std::vector< TubePointType >                PointListType;
  typedef PointListType *                             PointListPointer;
  typedef typename Superclass::PointType              PointType;
  typedef typename Superclass::TransformType          TransformType;
  typedef typename Superclass::SpatialObjectPointType SpatialObjectPointType;
  typedef VectorContainer< unsigned long, PointType > PointContainerType;
  typedef SmartPointer< PointContainerType >          PointContainerPointer;
  typedef typename Superclass::VectorType             VectorType;
  typedef typename Superclass::CovariantVectorType    CovariantVectorType;
  typedef typename Superclass::BoundingBoxType        BoundingBoxType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Method for creation through the object factory. */
  itkTypeMacro(TubeSpatialObject, PointBasedSpatialObject);

  /** Returns a reference to the list of the tube points. */
  virtual PointListType & GetPoints(void);

  /** Returns a reference to the list of the tube points. */
  virtual const PointListType & GetPoints(void) const;

  /** Set the list of tube points. */
  virtual void SetPoints(PointListType & newPoints);

  /** Return a point in the list given the index. */
  virtual const SpatialObjectPointType * GetPoint(unsigned long ind) const
  { return &( m_Points[ind] ); }

  /** Return a point in the list given the index */
  virtual SpatialObjectPointType * GetPoint(unsigned long ind)
  { return &( m_Points[ind] ); }

  /** Set a point in the list at the specified index */
  virtual void SetPoint(unsigned long ind, const TubePointType & pnt)
  { m_Points[ind] = pnt; }

  /** Remove a point in the list given the index */
  virtual void RemovePoint(unsigned long ind)
  { m_Points.erase(m_Points.begin() + ind); }

  /** Return the number of points in the list */
  virtual unsigned long GetNumberOfPoints(void) const
  { return m_Points.size(); }

  /** Set the type of tube end-type: 0 = flat, 1 = rounded */
  itkSetMacro(EndType, unsigned int);
  itkGetConstMacro(EndType, unsigned int);

  /** Remove the list of tube points */
  void Clear(void);

  /** Calculate the normalized tangent */
  bool ComputeTangentAndNormals(void);

  /** Remove duplicate points */
  unsigned int RemoveDuplicatePoints(unsigned int step = 1);

  /** Returns true if the tube is evaluable at the requested point,
   *  false otherwise. */
  bool IsEvaluableAt(const PointType & point,
                     unsigned int depth = 0, char *name = NULL) const;

  /** Returns the value of the tube at that point.
   *  Currently this function returns a binary value,
   *  but it might want to return a degree of membership
   *  in case of fuzzy tubes. */
  bool ValueAt(const PointType & point, double & value,
               unsigned int depth = 0, char *name = NULL) const;

  /** Returns true if the point is inside the tube, false otherwise. */
  bool IsInside(const PointType & point,
                unsigned int depth, char *name) const;

  /** Test whether a point is inside or outside the object
   *  For computational speed purposes, it is faster if the method does not
   *  check the name of the class and the current depth */
  virtual bool IsInside(const PointType & point) const;

  /** Compute the boundaries of the tube. */
  bool ComputeLocalBoundingBox() const;

  /** Set/Get the parent point which corresponds to the
   *  position of the point in the parent's points list */
  itkSetMacro(ParentPoint, int);
  itkGetConstMacro(ParentPoint, int);

  /** Set/Get a flag for vessel which are a "root" of a
   *  vascular network in the scene */
  itkSetMacro(Root, bool);
  itkGetConstMacro(Root, bool);

  /** Set/Get a flag for vessel which are an Artery */
  itkSetMacro(Artery, bool);
  itkGetConstMacro(Artery, bool);

  /** Copy the information from another SpatialObject */
  void CopyInformation(const DataObject *data);

protected:
  PointListType m_Points;

  int m_ParentPoint;

  unsigned int m_EndType;

  bool m_Root;
  bool m_Artery;

  TubeSpatialObject();
  virtual ~TubeSpatialObject();

  /** Method to print the object. */
  virtual void PrintSelf(std::ostream & os, Indent indent) const;

  /** TimeStamps */
  mutable unsigned long m_OldMTime;
  mutable unsigned long m_IndexToWorldTransformMTime;
private:
  TubeSpatialObject(const Self &); //purposely not implemented
  void operator=(const Self &);    //purposely not implemented
};
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTubeSpatialObject.txx"
#endif

#endif // __itkTubeSpatialObject_h
