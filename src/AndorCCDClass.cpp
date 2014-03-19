static const char *ClassId    = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        AndorCCDClass.cpp
//
// description : C++ source for the AndorCCDClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the AndorCCD once per process.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifdef WIN32
#include "tango.h"
#endif
#include <AndorCCD.h>
#include <AndorCCDClass.h>

#ifndef WIN32
#include "tango.h"
#endif

//+----------------------------------------------------------------------------
/**
 *	Create AndorCCDClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_AndorCCD_class(const char *name) {
		return AndorCCD_ns::AndorCCDClass::init(name);
	}
}


namespace AndorCCD_ns
{





//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
AndorCCDClass *AndorCCDClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::AndorCCDClass(string &s)
// 
// description : 	constructor for the AndorCCDClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
AndorCCDClass::AndorCCDClass(string &s):DeviceClass(s)
{

	cout2 << "Entering AndorCCDClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving AndorCCDClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::~AndorCCDClass()
// 
// description : 	destructor for the AndorCCDClass
//
//-----------------------------------------------------------------------------
AndorCCDClass::~AndorCCDClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
AndorCCDClass *AndorCCDClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new AndorCCDClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

AndorCCDClass *AndorCCDClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void AndorCCDClass::command_factory()
{

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum AndorCCDClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum AndorCCDClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum AndorCCDClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void AndorCCDClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new AndorCCD(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: AndorCCDClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void AndorCCDClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : enabledCooler
	enabledCoolerAttrib	*enabled_cooler = new enabledCoolerAttrib();
	att_list.push_back(enabled_cooler);

	//	Attribute : currentCoolingStatus
	currentCoolingStatusAttrib	*current_cooling_status = new currentCoolingStatusAttrib();
	Tango::UserDefaultAttrProp	current_cooling_status_prop;
	current_cooling_status_prop.set_description("Display the current status of the cooling system.");
	current_cooling_status->set_default_properties(current_cooling_status_prop);
	att_list.push_back(current_cooling_status);

	//	Attribute : temperatureTarget
	temperatureTargetAttrib	*temperature_target = new temperatureTargetAttrib();
	Tango::UserDefaultAttrProp	temperature_target_prop;
	temperature_target_prop.set_unit("Celsius");
	temperature_target_prop.set_display_unit("�C");
	temperature_target_prop.set_format("%d");
	temperature_target->set_default_properties(temperature_target_prop);
	att_list.push_back(temperature_target);

	//	Attribute : temperature
	temperatureAttrib	*temperature = new temperatureAttrib();
	Tango::UserDefaultAttrProp	temperature_prop;
	temperature_prop.set_unit("Celsius");
	temperature_prop.set_display_unit("�C");
	temperature_prop.set_format("%d");
	temperature->set_default_properties(temperature_prop);
	att_list.push_back(temperature);

	//	Attribute : adcMode
	adcModeAttrib	*adc_mode = new adcModeAttrib();
	Tango::UserDefaultAttrProp	adc_mode_prop;
	adc_mode_prop.set_description("Define the ADC frequency .<br>\nAvailable values are :<br>\n0-> 5 MHz<br>\n1-> 3 MHz<br>\n2-> 1 MHz<br>\n3-> 0.05 MHz<br>");
	adc_mode->set_default_properties(adc_mode_prop);
	att_list.push_back(adc_mode);

	//	Attribute : currentRate
	currentRateAttrib	*current_rate = new currentRateAttrib();
	Tango::UserDefaultAttrProp	current_rate_prop;
	current_rate_prop.set_description("Display the current ADC frequency in Mhz");
	current_rate->set_default_properties(current_rate_prop);
	att_list.push_back(current_rate);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}
















//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void AndorCCDClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	AndorCCDClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void AndorCCDClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "DetectorNum";
	prop_desc = "Detector Number.";
	prop_def  = "-1";
	vect_data.clear();
	vect_data.push_back("-1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "CoolingStatusAtStartUp";
	prop_desc = "Define wich Cooling status (ON/OFF) must be selected when start the device.";
	prop_def  = "OFF";
	vect_data.clear();
	vect_data.push_back("OFF");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedADCMode";
	prop_desc = "";
	prop_def  = "2";
	vect_data.clear();
	vect_data.push_back("2");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedTemperatureTarget";
	prop_desc = "";
	prop_def  = "-10";
	vect_data.clear();
	vect_data.push_back("-10");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		AndorCCDClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void AndorCCDClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Device specific for Andor CCD detector");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("  ");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace