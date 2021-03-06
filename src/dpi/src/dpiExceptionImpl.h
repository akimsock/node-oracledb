/* Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved. */

/******************************************************************************
 *
 * You may not use the identified files except in compliance with the Apache 
 * License, Version 2.0 (the "License.")
 *
 * You may obtain a copy of the License at 
 * http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 *
 * NAME
 *  dpiExceptionImpl.h
 *
 * DESCRIPTION
 *
 *****************************************************************************/

#ifndef DPIEXCEPTIONIMPL_ORACLE
# define DPIEXCEPTIONIMPL_ORACLE


#include <string>


#ifndef DPIEXCEPTION_ORACLE
# include <dpiException.h>
#endif


using std::string;

using namespace dpi;



/*---------------------------------------------------------------------------
                     PUBLIC TYPES
  ---------------------------------------------------------------------------*/

class ExceptionImpl : public Exception
{
 public:
                                // creation/termination
  ExceptionImpl(DpiError errno);

  ExceptionImpl(const char *origin, int errno, const char *message);

  virtual ~ExceptionImpl() throw();

  virtual const char * what() const throw();
  
  virtual int          errno() const throw();
  
  virtual const char * origin() const throw();
  
private:
  string origin_;
  int    errno_;
  string message_;
  
};




#endif                                              /* DPIEXCEPTIONIMPL_ORACLE */
