//=============================================================================
//
// file :         EigerClass.h
//
// description :  Include for the EigerClass root class.
//                This class is the singleton class for
//                the Eiger device class.
//                It contains all properties and methods which the 
//                Eiger requires only once e.g. the commands.
//			
// project :      TANGO Device Server
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
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _EigerCLASS_H
#define _EigerCLASS_H

#include <tango.h>
#include <Eiger.h>


namespace Eiger_ns
{//=====================================
//	Define classes for attributes
//=====================================
class compressionAttrib: public Tango::Attr
{
public:
	compressionAttrib():Attr("compression", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~compressionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_compression(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_compression(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_compression_allowed(ty);}
};

class humidityAttrib: public Tango::Attr
{
public:
	humidityAttrib():Attr("humidity", Tango::DEV_DOUBLE, Tango::READ) {};
	~humidityAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_humidity(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_humidity_allowed(ty);}
};

class temperatureAttrib: public Tango::Attr
{
public:
	temperatureAttrib():Attr("temperature", Tango::DEV_DOUBLE, Tango::READ) {};
	~temperatureAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_temperature(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_temperature_allowed(ty);}
};

class photonEnergyAttrib: public Tango::Attr
{
public:
	photonEnergyAttrib():Attr("photonEnergy", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~photonEnergyAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_photonEnergy(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_photonEnergy(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_photonEnergy_allowed(ty);}
};

class thresholdEnergyAttrib: public Tango::Attr
{
public:
	thresholdEnergyAttrib():Attr("thresholdEnergy", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~thresholdEnergyAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_thresholdEnergy(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_thresholdEnergy(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_thresholdEnergy_allowed(ty);}
};

class efficiencyCorrectionAttrib: public Tango::Attr
{
public:
	efficiencyCorrectionAttrib():Attr("efficiencyCorrection", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~efficiencyCorrectionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_efficiencyCorrection(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_efficiencyCorrection(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_efficiencyCorrection_allowed(ty);}
};

class virtualPixelCorrectionAttrib: public Tango::Attr
{
public:
	virtualPixelCorrectionAttrib():Attr("virtualPixelCorrection", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~virtualPixelCorrectionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_virtualPixelCorrection(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_virtualPixelCorrection(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_virtualPixelCorrection_allowed(ty);}
};

class pixelMaskAttrib: public Tango::Attr
{
public:
	pixelMaskAttrib():Attr("pixelMask", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~pixelMaskAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_pixelMask(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_pixelMask(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_pixelMask_allowed(ty);}
};

class flatfieldCorrectionAttrib: public Tango::Attr
{
public:
	flatfieldCorrectionAttrib():Attr("flatfieldCorrection", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~flatfieldCorrectionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_flatfieldCorrection(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_flatfieldCorrection(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_flatfieldCorrection_allowed(ty);}
};

class countrateCorrectionAttrib: public Tango::Attr
{
public:
	countrateCorrectionAttrib():Attr("countrateCorrection", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~countrateCorrectionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Eiger *>(dev))->read_countrateCorrection(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Eiger *>(dev))->write_countrateCorrection(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Eiger *>(dev))->is_countrateCorrection_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
//
// The EigerClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	EigerClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static EigerClass *init(const char *);
	static EigerClass *instance();
	~EigerClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	EigerClass(string &);
	static EigerClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace Eiger_ns

#endif // _EIGERCLASS_H
