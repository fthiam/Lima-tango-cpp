//=============================================================================
//
// file :        Maxipix.h
//
// description : Include for the Maxipix class.
//
// project :	Device specific for Maxipix detector
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//		 BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _MAXIPIX_H
#define _MAXIPIX_H

#include <tango.h>
//using namespace Tango;

/**
 * @author	$Author:  $
 * @version	$Revision:  $
 */

 //	Add your own constant definitions here.
 //-----------------------------------------------

#include "Factory.h"

#include "lima/HwInterface.h"
#include "lima/CtControl.h"
#include "lima/CtAcquisition.h"
#include "lima/CtImage.h"

#include <yat4tango/PropertyHelper.h>
#include <MaxipixInterface.h>
#include <MaxipixCamera.h>

#define MAX_ATTRIBUTE_STRING_LENGTH     256
#define DEVICE_VERSION  "1.0.0"


using namespace lima;
using namespace std;
using namespace yat4tango;

namespace Maxipix_ns
{

/**
 * Class Description:
 * 
 */

/*
 *	Device States Description:
*  Tango::FAULT :
*  Tango::INIT :
*  Tango::RUNNING :
*  Tango::STANDBY :
 */


class Maxipix: public Tango::Device_4Impl
{
public :
	//	Add your own data members here
	//-----------------------------------------


	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attribute member data.
 */
//@{
		Tango::DevString	*attr_deviceVersion_read;
		Tango::DevDouble	*attr_energyThreshold_read;
		Tango::DevDouble	attr_energyThreshold_write;
		Tango::DevString	*attr_fillMode_read;
		Tango::DevString	attr_fillMode_write;
//@}

/**
 * @name Device properties
 * Device properties member data.
 */
//@{
/**
 *	Espia device number .<br>
 */
	Tango::DevLong	espiaDeviceNumber;
/**
 *	Define the path of the configuration file .<br>
 *	
 */
	string	configurationPath;
/**
 *	Define the name of the configuration file .<br>
 */
	string	configurationName;
/**
 *	Enable/Disable reconstruction.<br>
 */
	Tango::DevBoolean	useReconstruction;
//@}

/**
 *	@name Device properties
 *	Device property member data.
 */
//@{
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Maxipix(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Maxipix(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	Maxipix(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one destructor is defined for this class */
//@{
/**
 * The object destructor.
 */	
	~Maxipix() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
/**
 *	Always executed method before execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name Maxipix methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
	virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for deviceVersion acquisition result.
 */
	virtual void read_deviceVersion(Tango::Attribute &attr);
/**
 *	Extract real attribute values for energyThreshold acquisition result.
 */
	virtual void read_energyThreshold(Tango::Attribute &attr);
/**
 *	Write energyThreshold attribute values to hardware.
 */
	virtual void write_energyThreshold(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for fillMode acquisition result.
 */
	virtual void read_fillMode(Tango::Attribute &attr);
/**
 *	Write fillMode attribute values to hardware.
 */
	virtual void write_fillMode(Tango::WAttribute &attr);
/**
 *	Read/Write allowed for deviceVersion attribute.
 */
	virtual bool is_deviceVersion_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for energyThreshold attribute.
 */
	virtual bool is_energyThreshold_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for fillMode attribute.
 */
	virtual bool is_fillMode_allowed(Tango::AttReqType type);
/**
 * This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *	@return	State Code
 *	@exception DevFailed
 */
	virtual Tango::DevState	dev_state();

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	

	// return true if the device is correctly initialized in init_device
	bool is_device_initialized(){return m_is_device_initialized;};

protected :	
	//	Add your own data members here
	//-----------------------------------------
    //state & status stuff
    bool                        m_is_device_initialized ;
    stringstream                m_status_message;
    //lima OBJECTS
    Maxipix::Interface* m_hw;
    CtControl*          m_ct;
    Maxipix::Camera*    m_camera;	
	
};

}	// namespace_ns

#endif	// _MAXIPIX_H
