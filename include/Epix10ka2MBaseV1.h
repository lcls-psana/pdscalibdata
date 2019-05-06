#ifndef PDSCALIBDATA_EPIX10KA2MBASEV1_H
#define PDSCALIBDATA_EPIX10KA2MBASEV1_H

//------------------------------------------------------------------------
// File and Version Information:
//      $Revision$
//      $Id$
//      $HeadURL$
//      $Date$
//
// Author: Mikhail Dubrovin
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
//#include <string>
#include <cstring>  // for memcpy

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
//#include "ndarray/ndarray.h"
//#include "pdsdata/psddl/andor.ddl.h"

//-----------------------------

namespace pdscalibdata {

/**
 *  class Epix10ka2MBaseV1 contains common parameters and methods for Andor camera. 
 *
 *  This software was developed for the LCLS project.  
 *  If you use all or part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Mikhail Dubrovin
 */

class Epix10ka2MBaseV1 {
public:

  typedef unsigned 	shape_t;
  typedef double  	cmod_t;

  const static size_t   Ndim = 3; 
  const static size_t   Segs = 16; 
  const static size_t   Rows = 352; 
  const static size_t   Cols = 384; 
  const static size_t   Size = Segs*Rows*Cols; 
  const static size_t   SizeCM = 16; 

  const shape_t* shape_base() { return &m_shape[0]; }
  const cmod_t*  cmod_base()  { return &m_cmod[0]; }
  const size_t   size_base()  { return Size; }

  ~Epix10ka2MBaseV1 () {};

protected:

  Epix10ka2MBaseV1 (){ 
    shape_t shape[Ndim]={Segs,Rows,Cols};            
    cmod_t cmod[SizeCM]={4,6,30,10, 0,0,0,0, 0,0,0,0, 0,0,0,0}; 
    // ???? 4-Epix100a, 1-median for 16 352x96 banks, 20-maximal allowed correction
    std::memcpy(m_shape, &shape[0], sizeof(shape_t)*Ndim);
    std::memcpy(m_cmod,  &cmod[0],  sizeof(cmod_t)*SizeCM);
  };
  
private:
  shape_t m_shape[Ndim];
  cmod_t  m_cmod[SizeCM];
};

} // namespace pdscalibdata

#endif // PDSCALIBDATA_EPIX10KA2MBASEV1_H
