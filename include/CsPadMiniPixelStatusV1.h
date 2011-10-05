#ifndef PDSCALIBDATA_CSPADMINIPIXELSTATUSV1_H
#define PDSCALIBDATA_CSPADMINIPIXELSTATUSV1_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CsPadMiniPixelStatusV1.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <boost/utility.hpp>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "pdsdata/cspad/Detector.hh"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace pdscalibdata {

/// @addtogroup pdscalibdata

/**
 *  @ingroup pdscalibdata
 *
 *  @brief Pixel status data for CsPad::MiniElementV1.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov
 */

class CsPadMiniPixelStatusV1 : boost::noncopyable {
public:

  enum { Sections = 2 };
  enum { Columns = Pds::CsPad::ColumnsPerASIC };
  enum { Rows = Pds::CsPad::MaxRowsPerASIC*2 };
  enum { Size = Sections*Columns*Rows };

  // NOTE: Using the same codes as in CspadCorrector
  enum PixelStatus {
    VeryHot=1,
    Hot=2,
    Cold=4
  };

  typedef uint16_t status_t;
  // organization of data in MiniElement is quite different from
  // regular CsPad elements
  typedef status_t StatusCodes[Columns][Rows][Sections];

  /// Default constructor, all pixel codes set to 0
  CsPadMiniPixelStatusV1 () ;

  /**
   *  Read all codes from file.
   *
   *  @throw std::exception
   */
  CsPadMiniPixelStatusV1 (const std::string& fname) ;

  // Destructor
  ~CsPadMiniPixelStatusV1 () ;

  // access status data
  const StatusCodes& status() const { return m_status; }

protected:

private:

  // Data members
  StatusCodes m_status;

};

} // namespace pdscalibdata

#endif // PDSCALIBDATA_CSPADMINIPIXELSTATUSV1_H