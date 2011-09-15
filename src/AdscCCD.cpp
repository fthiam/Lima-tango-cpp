static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         AdscCCD.cpp
//
// description :  C++ source for the AdscCCD and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                AdscCCD are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
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
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name         |  Method name
//	----------------------------------------
//  State                |  dev_state()
//  Status               |  dev_status()
//  SetHeaderParameters  |  set_header_parameters()
//
//===================================================================



#include <AdscCCD.h>
#include <AdscCCDClass.h>
#include <tango.h>
#include <PogoHelper.h>
namespace AdscCCD_ns
{

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::AdscCCD(string &s)
// 
// description : 	constructor for simulated AdscCCD
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
AdscCCD::AdscCCD(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str())
{
	init_device();
}

AdscCCD::AdscCCD(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s)
{
	init_device();
}

AdscCCD::AdscCCD(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d)
{
	init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void AdscCCD::delete_device()
{
  DELETE_DEVSTRING_ATTRIBUTE(attr_imagePath_read);
  DELETE_DEVSTRING_ATTRIBUTE(attr_fileName_read);   
  //	Delete device allocated objects
  //!!!! ONLY LimaDetector device can do this !!!!
  //if(m_ct!=0)
  //{
  //    ControlFactory::instance().reset("AdscCCD");
  //    m_ct = 0;
  //}
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void AdscCCD::init_device()
{
	INFO_STREAM << "AdscCCD::AdscCCD() create device " << device_name << endl;

	// Initialise variables to default values
	//--------------------------------------------
  CREATE_DEVSTRING_ATTRIBUTE(attr_imagePath_read,MAX_ATTRIBUTE_STRING_LENGTH);
  CREATE_DEVSTRING_ATTRIBUTE(attr_fileName_read,MAX_ATTRIBUTE_STRING_LENGTH);    
  m_is_device_initialized = false;
  m_status_message.str("");

  try
  {
    //- get the main object used to pilot the lima framework
    //in fact LimaDetector is create the singleton control objet
    //so this call, will only return existing object!!
    m_ct = ControlFactory::instance().get_control("AdscCCD");
    
    //- get interface to specific camera
    m_hw = dynamic_cast<Adsc::Interface*>(m_ct->hwInterface());
    if(m_hw==0)
    {
      INFO_STREAM<<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"AdscCCD"<<") !"<< endl;
      m_status_message <<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"AdscCCD"<<") !"<< endl;
      m_is_device_initialized = false;
      set_state(Tango::INIT);
      return;
    }

  }
  catch(Exception& e)
  {
    INFO_STREAM<<"Initialization Failed : "<<e.getErrMsg()<<endl;
    m_status_message <<"Initialization Failed : "<<e.getErrMsg( )<< endl;
    m_is_device_initialized = false;
    set_state(Tango::INIT);
    return;
  }
  catch(...)
  {
    INFO_STREAM<<"Initialization Failed : UNKNOWN"<<endl;
    m_status_message <<"Initialization Failed : UNKNOWN"<< endl;
    set_state(Tango::INIT);
    m_is_device_initialized = false;
    return;
  }
  m_is_device_initialized = true;
  set_state(Tango::STANDBY);
  this->dev_state();
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void AdscCCD::always_executed_hook()
{
	
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "AdscCCD::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
	//	Add your own code here
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_imagePath
// 
// description : 	Extract real attribute values for imagePath acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_imagePath(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_imagePath(Tango::Attribute &attr) entering... "<< endl;
  try
  {
    strcpy(*attr_imagePath_read, m_hw->getImagePath().c_str());
    attr.set_value(attr_imagePath_read);
  }
  catch(Tango::DevFailed& df)
  {
    ERROR_STREAM << df << endl;
    //- rethrow exception
    Tango::Except::re_throw_exception(df,
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (string(df.errors[0].desc).c_str()),
                 static_cast<const char*> ("AdscCCD::read_imagePath"));
  }
  catch(Exception& e)
  {
    ERROR_STREAM << e.getErrMsg() << endl;
    //- throw exception
    Tango::Except::throw_exception(
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (e.getErrMsg().c_str()),
                 static_cast<const char*> ("AdscCCD::read_imagePath"));
  }  
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_imagePath
// 
// description : 	Write imagePath attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_imagePath(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_imagePath(Tango::WAttribute &attr) entering... "<< endl;
  try
  {
    attr.get_write_value(attr_imagePath_write);
    m_hw->setImagePath(attr_imagePath_write);
  }
  catch(Tango::DevFailed& df)
  {
    ERROR_STREAM << df << endl;
    //- rethrow exception
    Tango::Except::re_throw_exception(df,
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (string(df.errors[0].desc).c_str()),
                 static_cast<const char*> ("AdscCCD::write_imagePath"));
  }
  catch(Exception& e)
  {
    ERROR_STREAM << e.getErrMsg() << endl;
    //- throw exception
    Tango::Except::throw_exception(
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (e.getErrMsg().c_str()),
                 static_cast<const char*> ("AdscCCD::write_imagePath"));
  }   
}


//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_fileName
// 
// description : 	Extract real attribute values for fileName acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_fileName(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_fileName(Tango::Attribute &attr) entering... "<< endl;
  try
  {
    strcpy(*attr_fileName_read, m_hw->getFileName().c_str());
    attr.set_value(attr_fileName_read);
  }
  catch(Tango::DevFailed& df)
  {
    ERROR_STREAM << df << endl;
    //- rethrow exception
    Tango::Except::re_throw_exception(df,
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (string(df.errors[0].desc).c_str()),
                 static_cast<const char*> ("AdscCCD::read_fileName"));
  }
  catch(Exception& e)
  {
    ERROR_STREAM << e.getErrMsg() << endl;
    //- throw exception
    Tango::Except::throw_exception(
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (e.getErrMsg().c_str()),
                 static_cast<const char*> ("AdscCCD::read_fileName"));
  }    
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_fileName
// 
// description : 	Write fileName attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_fileName(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_fileName(Tango::WAttribute &attr) entering... "<< endl;
  try
  {
    attr.get_write_value(attr_fileName_write);
    m_hw->setFileName(attr_fileName_write);
  }
  catch(Tango::DevFailed& df)
  {
    ERROR_STREAM << df << endl;
    //- rethrow exception
    Tango::Except::re_throw_exception(df,
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (string(df.errors[0].desc).c_str()),
                 static_cast<const char*> ("AdscCCD::write_fileName"));
  }
  catch(Exception& e)
  {
    ERROR_STREAM << e.getErrMsg() << endl;
    //- throw exception
    Tango::Except::throw_exception(
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (e.getErrMsg().c_str()),
                 static_cast<const char*> ("AdscCCD::write_fileName"));
  }   
}


//+------------------------------------------------------------------
/**
 *	method:	AdscCCD::set_header_parameters
 *
 *	description:	method to execute "SetHeaderParameters"
 *	Set crystallographic parameters reported in the image header. <br>
 *	
 *	[parm_name=value];[parm_name=value];...<br>
 *	
 *	Possible values :<br>
 *	DISTANCE=300.5;PHI=88.5;...;WAVELENGTH=0.987<br>
 *
 * @param	argin	
 *
 */
//+------------------------------------------------------------------
void AdscCCD::set_header_parameters(Tango::DevString argin)
{
	DEBUG_STREAM << "AdscCCD::set_header_parameters(): entering... !" << endl;

	//	Add your own code to control device here
  try
  {
    std::string str_header_parameters = argin;
    m_hw->setHeaderParameters(str_header_parameters);
  }
  catch(Tango::DevFailed& df)
  {
    ERROR_STREAM << df << endl;
    //- rethrow exception
    Tango::Except::re_throw_exception(df,
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (string(df.errors[0].desc).c_str()),
                 static_cast<const char*> ("AdscCCD::set_header_parameters"));
  }
  catch(Exception& e)
  {
    ERROR_STREAM << e.getErrMsg() << endl;
    //- throw exception
    Tango::Except::throw_exception(
                 static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                 static_cast<const char*> (e.getErrMsg().c_str()),
                 static_cast<const char*> ("AdscCCD::set_header_parameters"));
  }
}


//+------------------------------------------------------------------
/**
 *	method:	AdscCCD::dev_state
 *
 *	description:	method to execute "State"
 *	This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *
 * @return	State Code
 *
 */
//+------------------------------------------------------------------
Tango::DevState AdscCCD::dev_state()
{
	Tango::DevState	argout = DeviceImpl::dev_state();
	DEBUG_STREAM << "AdscCCD::dev_state(): entering... !" << endl;

	//	Add your own code to control device here

  stringstream    DeviceStatus;
  DeviceStatus     << "";
  Tango::DevState DeviceState    = Tango::STANDBY;
  if(!m_is_device_initialized )
  {
    DeviceState            = Tango::INIT;
    DeviceStatus        << m_status_message.str();
  }
  else if (m_ct==0)
  {
    DeviceState            = Tango::INIT;
    DeviceStatus        <<"Initialization Failed : Unable to get the lima control object !\n\n";
  }
  else
  {
    CtControl::Status status;
    m_ct->getStatus(status);
    if (status.AcquisitionStatus == lima::AcqReady)
    {
      HwInterface::StatusType state;
      m_hw->getStatus(state); 

      if(state.acq == AcqRunning && state.det == DetExposure)
      {
        DeviceState=Tango::RUNNING;
        DeviceStatus<<"Acquisition is Running ...\n"<<endl;
      }
      else if(state.acq == AcqFault && state.det == DetFault)
      {                 
        DeviceState=Tango::INIT;//INIT
        DeviceStatus<<"Acquisition is in Init\n"<<endl;
      }
      else if(state.acq == AcqFault && state.det == DetIdle)
      {                 
        DeviceState=Tango::FAULT;//FAULT
        DeviceStatus<<"Acquisition is in Fault\n"<<endl;
      }
      else
      {
        DeviceState=Tango::STANDBY;
        DeviceStatus<<"Waiting for Request ...\n"<<endl;
      }
    }
    else if(status.AcquisitionStatus == lima::AcqRunning)
    {           
      DeviceState=Tango::RUNNING;
      DeviceStatus<<"Acquisition is Running ...\n"<<endl;
    }
    else
    {      
      HwInterface::StatusType state;
      m_hw->getStatus(state); 
      if(state.acq == AcqFault && state.det == DetFault)
      {                 
        DeviceState=Tango::INIT;//INIT
        DeviceStatus<<"Acquisition is in Init\n"<<endl;
      }
      else
      {
        DeviceState=Tango::FAULT;//FAULT
        DeviceStatus<<"Acquisition is in Fault\n"<<endl;
      }
    }
  }

  set_state(DeviceState);
  set_status(DeviceStatus.str());

  argout = DeviceState;
  return argout;
}

}	//	namespace