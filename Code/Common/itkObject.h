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
/*=========================================================================
 *
 *  Portions of this file are subject to the VTK Toolkit Version 3 copyright.
 *
 *  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
 *
 *  For complete copyright, license and disclaimer of warranty information
 *  please refer to the NOTICE file at the top of the ITK source tree.
 *
 *=========================================================================*/
#ifndef __itkObject_h
#define __itkObject_h

#include "itkLightObject.h"
#include "itkEventObject.h"
#include "itkMetaDataDictionary.h"

namespace itk
{
class SubjectImplementation;
class Command;

/** \class Object
 * \brief Base class for most itk classes.
 *
 * Object is the second-highest level base class for most itk objects.
 * It extends the base object functionality of LightObject by
 * implementing callbacks (via object/observer), debug flags/methods,
 * and modification time tracking. Most ITK classes should be a subclass
 * of Object due to the need to keep track of modified time.
 *
 * \ingroup ITKSystemObjects
 * \ingroup DataRepresentation
 */
class ITKCommon_EXPORT Object:public LightObject
{
public:
  /** Smart pointer typedef support. */
  typedef Object                     Self;
  typedef LightObject                Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  static Pointer New();

  /** Create an object from an instance, potentially deferring to a
   * factory.  This method allows you to create an instance of an
   * object that is exactly the same type as the referring object.
   * This is useful in cases where an object has been cast back to a
   * base class. */
  virtual LightObject::Pointer CreateAnother() const;

  /** Standard part of all itk objects. */
  itkTypeMacro(Object, LightObject);

  /** Turn debugging output on.  */
  virtual void DebugOn() const;

  /** Turn debugging output off.  */
  virtual void DebugOff() const;

  /** Get the value of the debug flag.  */
  bool GetDebug() const;

  /** Set the value of the debug flag. A non-zero value turns debugging on. */
  void SetDebug(bool debugFlag) const;

  /** Return this objects modified time.  */
  virtual unsigned long GetMTime() const;

  /** Update the modification time for this object. Many filters rely on the
   * modification time to determine if they need to recompute their data.  */
  virtual void Modified() const;

  /** Increase the reference count (mark as used by another object).  */
  virtual void Register() const;

  /** Decrease the reference count (release by another object).  */
  virtual void UnRegister() const;

  /** Sets the reference count (use with care)  */
  virtual void SetReferenceCount(int);

  /** This is a global flag that controls whether any debug, warning
   *  or error messages are displayed.  */
  static void SetGlobalWarningDisplay(bool flag);

  static bool GetGlobalWarningDisplay();

  static void GlobalWarningDisplayOn()
  { Object::SetGlobalWarningDisplay(true); }
  static void GlobalWarningDisplayOff()
  { Object::SetGlobalWarningDisplay(false); }

  /** Allow people to add/remove/invoke observers (callbacks) to any ITK
   * object. This is an implementation of the subject/observer design
   * pattern. An observer is added by specifying an event to respond to
   * and an itk::Command to execute. It returns an unsigned long tag
   * which can be used later to remove the event or retrieve the
   * command.  The memory for the Command becomes the responsibility of
   * this object, so don't pass the same instance of a command to two
   * different objects  */
  unsigned long AddObserver(const EventObject & event, Command *);

  unsigned long AddObserver(const EventObject & event, Command *) const;

  /** Get the command associated with the given tag.  NOTE: This returns
   * a pointer to a Command, but it is safe to assign this to a
   * Command::Pointer.  Since Command inherits from LightObject, at this
   * point in the code, only a pointer or a reference to the Command can
   * be used.   */
  Command * GetCommand(unsigned long tag);

  /** Call Execute on all the Commands observing this event id. */
  void InvokeEvent(const EventObject &);

  /** Call Execute on all the Commands observing this event id.
   * The actions triggered by this call doesn't modify this object. */
  void InvokeEvent(const EventObject &) const;

  /** Remove the observer with this tag value. */
  void RemoveObserver(unsigned long tag);

  /** Remove all observers . */
  void RemoveAllObservers();

  /** Return true if an observer is registered for this event. */
  bool HasObserver(const EventObject & event) const;

  /**
   * \return A reference to this objects MetaDataDictionary.
   * \warning This reference may be changed.
   */
  MetaDataDictionary & GetMetaDataDictionary(void);

  /**
   * \return A constant reference to this objects MetaDataDictionary.
   */
  const MetaDataDictionary & GetMetaDataDictionary(void) const;

  /**
   * \return Set the MetaDataDictionary
   */
  void SetMetaDataDictionary(const MetaDataDictionary & rhs);

protected:
  Object();
  virtual ~Object();

  /** Methods invoked by Print() to print information about the object
   * including superclasses. Typically not called by the user (use Print()
   * instead) but used in the hierarchical print process to combine the
   * output of several classes.  */
  virtual void PrintSelf(std::ostream & os, Indent indent) const;

  bool PrintObservers(std::ostream & os, Indent indent) const;

private:
  Object(const Self &);         //purposely not implemented
  void operator=(const Self &); //purposely not implemented

  /** Enable/Disable debug messages. */
  mutable bool m_Debug;

  /** Keep track of modification time. */
  mutable TimeStamp m_MTime;

  /** Global object debug flag. */
  static bool m_GlobalWarningDisplay;

  /** Implementation class for Subject/Observer Pattern.
   * This is only allocated if used. */
  SubjectImplementation *m_SubjectImplementation;
  /**
   * Implementation for holding Object MetaData
   * @see itk::MetaDataDictionary
   * @see itk::MetaDataObjectBase
   * @see itk::MetaDataObject
   * This is only allocated if used.
   */
  mutable MetaDataDictionary *m_MetaDataDictionary;
};
} // end namespace itk

#endif
