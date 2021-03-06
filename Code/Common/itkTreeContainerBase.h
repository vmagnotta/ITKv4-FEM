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
#ifndef __itkTreeContainerBase_h
#define __itkTreeContainerBase_h

#include "itkMacro.h"
#include <iostream>
#include <itkTreeNode.h>

namespace itk
{
template< class TValueType >
class TreeContainerBase:public Object
{
public:

  typedef Object                     Superclass;
  typedef TreeContainerBase          Self;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  typedef TValueType ValueType;

  /** Run-time type information (and related methods). */
  itkTypeMacro(TreeContainerBase, Object);

  /** Set the root element.
   * A new node is created and the element is added to the node */
  virtual bool SetRoot(const TValueType element) = 0;

  /** Set the root has a node */
  virtual bool SetRoot(TreeNode< TValueType > *node) = 0;

  /** Return true if the tree contains the element */
  virtual bool Contains(const TValueType element) = 0;

  /** Return the number of nodes in the tree */
  virtual int Count() const = 0;

  /** Return if the element is a leaf */
  virtual bool IsLeaf(const TValueType element) = 0;

  /** Return if the element is root */
  virtual bool IsRoot(const TValueType element) = 0;

  /** Clear the tree */
  virtual bool Clear() = 0;

  /** Get the root as a node */
  virtual const TreeNode< TValueType > * GetRoot() const = 0;

  /** Set if the tree is a subtree */
  void SetSubtree(bool val) { m_SubTree = val; }
protected:

  TreeContainerBase() {}
  virtual ~TreeContainerBase() {}
  bool m_SubTree;
};
} // namespace itk

#endif
