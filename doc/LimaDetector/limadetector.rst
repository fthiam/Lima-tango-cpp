LimaDetector class
====================

**LimaDetector** is the generic class and it provides a unique interface to control any supported camera. One can find below the 
properties, commands, and attributes. 
At the 1st start of the device server, all the properties are created with the default values.

To run a LimaDetector device you will need at least to configure the **DetectorType** property. This property is used by the LimaDetector device to communicate with the proper camera plugin. Please refer a specific camera (e.g Basler) device chapter for further information.

Properties
----------
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Property name               |Default value                        |Description                                                                                          |
+============================+=====================================+=====================================================================================================+
|DetectorType                |SimulatorCCD                         | | Define the type of the Detector. Availables types : (one of these)                                |
|                            |                                     | | AndorCCD                                                                                          |
|                            |                                     | | AviexCCD                                                                                          |
|                            |                                     | | BaslerCCD                                                                                         |
|                            |                                     | | Eiger                                                                                             |
|                            |                                     | | Hamamatsu                                                                                         |
|                            |                                     | | ImXpad                                                                                            |
|                            |                                     | | MarCCD                                                                                            |
|                            |                                     | | Maxipix                                                                                           |
|                            |                                     | | Merlin                                                                                            |
|                            |                                     | | Pco                                                                                               |
|                            |                                     | | PerkinElmer                                                                                       |
|                            |                                     | | PilatusPixelDetector                                                                              |
|                            |                                     | | PrincetonCCD                                                                                      |
|                            |                                     | | ProsilicaCCD                                                                                      |
|                            |                                     | | SimulatorCCD                                                                                      |
|                            |                                     | | UviewCCD                                                                                          |
|                            |                                     | | XpadPixelDetector                                                                                 |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|AutoSaveResetRoi            |false                                |Memorize the "full frame" automatically at the call of "ResetRoi"                                    |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|AutoStartVideo              |false                                | | Allows calling automatically the "Start" command when:                                            |
|                            |                                     | | The device starts                                                                                 |
|                            |                                     | | After calling the "Init" command                                                                  |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DebugFormats                | | DateTime                          | | Define Lima traces formats. Availables values : (a combination of these)                          |
|                            | | Module                            | | DateTime                                                                                          |
|                            | | Type                              | | Thread                                                                                            |
|                            |                                     | | Module                                                                                            |
|                            |                                     | | Obj                                                                                               |
|                            |                                     | | Funct                                                                                             |
|                            |                                     | | FileLine                                                                                          |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DebugLevels                 | | Fatal                             | | Define Lima traces levels. Availables values : (a combination of these)                           |
|                            | | Error                             | | Fatal                                                                                             |
|                            | | Warning                           | | Error                                                                                             |
|                            |                                     | | Warning                                                                                           |
|                            |                                     | | Trace                                                                                             |
|                            |                                     | | Funct                                                                                             |
|                            |                                     | | Param                                                                                             |
|                            |                                     | | Return                                                                                            |
|                            |                                     | | Always                                                                                            |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DebugModules                | | Hardware                          | | Define Lima traces modules. Availables values : (a combination of these)                          |
|                            | | Control                           | | None                                                                                              |
|                            | | Common                            | | Hardware                                                                                          |
|                            | | Camera                            | | Warning                                                                                           |
|                            |                                     | | Control                                                                                           |
|                            |                                     | | Common                                                                                            |
|                            |                                     | | Camera                                                                                            |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DetectorDescription         |This is my Simulator                 |Detector user-defined text to identify the engine.                                                   |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DetectorPixelDepth          |16                                   | | Define the pixel depth of the detector. Availables values :                                       |
|                            |                                     | | 8                                                                                                 |
|                            |                                     | | 12                                                                                                |
|                            |                                     | | 16                                                                                                |
|                            |                                     | | 16S                                                                                               |
|                            |                                     | | 24                                                                                                |
|                            |                                     | | 24S                                                                                               |
|                            |                                     | | 32                                                                                                |
|                            |                                     | | 32S                                                                                               |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|DetectorVideoMode           |NONE                                 | | Define the format of video stream. Availables types :                                             |
|                            |                                     | | NONE                                                                                              |
|                            |                                     | | Y8                                                                                                |
|                            |                                     | | Y16                                                                                               |
|                            |                                     | | Y32                                                                                               |
|                            |                                     | | Y64                                                                                               |
|                            |                                     | | RGB555                                                                                            |
|                            |                                     | | RGB565                                                                                            |
|                            |                                     | | RGB24                                                                                             |
|                            |                                     | | RGB32                                                                                             |
|                            |                                     | | BGR24                                                                                             |
|                            |                                     | | BGR32                                                                                             |
|                            |                                     | | BAYER_RG8                                                                                         |
|                            |                                     | | BAYER_RG16                                                                                        |
|                            |                                     | | I420                                                                                              |
|                            |                                     | | YUV411                                                                                            |
|                            |                                     | | YUV422                                                                                            |
|                            |                                     | | YUV444                                                                                            |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ExpertBufferMaxMemoryPercent|70                                   |Define the Percent of available system memory reserved to Lima buffer control :                      |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ExpertNbPoolThread          |4                                    |Defines the number of threads dedicated to process images in the PricessLib                          |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ExpertUsePrepareCmd         |false                                |If true, a call of 'Prepare' command is necessary before each 'Snap' or 'Start' command.             |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|FileIndexPattern            |%06d                                 | | Define the pattern of the index used for image files names.                                       |
|                            |                                     | | Nota : %04d mean that file name index will be end with exactly 4 digits filled by '0' if necessary|
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|FileManagedMode             |SOFTWARE                             | | Define the File managed Mode :                                                                    |
|                            |                                     | | HARDWARE: use the hardware saving system                                                          |
|                            |                                     | | SOFTWARE: use the software saving system                                                          |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|FileMemoryMode              |NO_COPY                              | | Available only for Nexus format : Set the SetDataItemMemoryMode(). Available values :             |
|                            |                                     | | COPY: the nexus lib make its own copy of the image and then works on it                           |
|                            |                                     | | NO_COPY: the nexus lib use the buffer image allocated by the lima memory manager                  |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|FileTimestampEnabled        |true                                 |Available only for Nexus format: enable the timestamp                                                |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|FileWriteMode               |SYNCHRONOUS                          | | Available only for Nexus format : Set the SetWriteMode(). Available values :                      |
|                            |                                     | | ASYNCHRONOUS                                                                                      |
|                            |                                     | | SYNCHRONOUS                                                                                       |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ImageOpMode                 |HardAndSoft                          | | Define ImageOpMode for Roi/Binning/etc... Available values :                                      |
|                            |                                     | | HardOnly                                                                                          |
|                            |                                     | | SoftOnly                                                                                          |
|                            |                                     | | HardAndSoft                                                                                       |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ImageSource                 |VIDEO                                | | Choose the source of Data given to the image attribute :                                          |
|                            |                                     | | VIDEO : use ctVideo->LastImage() : 				                                                 |
																   | |	       ATTENTION: specifics process as Flip/Rotation/Mask/etc... are disabled in this mode !	 |
|                            |                                     | | ACQUISITION : use ctControl->ReadImage()                                                          |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|SpecialDisplayType          |NOT_USED                             |Special type of the image attribute for display and saving (NOT_USED, FLOAT, ...)                    |
+----------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+

Attributes
----------
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|  Attribute name            |  Read/Write  |  Type                         |  Description                                                                                        |
+============================+==============+===============================+=====================================================================================================+
|detectorDescription         |R             |DevString                      |Detector user-defined text to identify the engine.                                                   |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|detectorType                |R             |DevString                      |type of the Detector                                                                                 |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|detectorModel               |R             |DevString                      |model of the Detector                                                                                |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|detectorWidthMax            |R             |DevUShort                      |Maximum width                                                                                        |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|detectorHeightMax           |R             |DevUShort                      |Maximum height                                                                                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|detectorPixelDepth          |R             |DevUShort                      |Pixel resolution in bits (eg: 8 , 12 , 16 ...)                                                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|binnedWidthMax              |R             |DevUShort                      |Detector max width taking into account the current Horizontal Binning                                |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|binnedHeightMax             |R             |DevUShort                      |Detector max width taking into account the current Vertical Binning                                  |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|triggerMode                 |R/W           |DevString                      |Trigger Modes. Get available values via the command GetAttributeAvailableValues("triggerModes")      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|acquisitionMode             |R/W           |DevString                      | | Acquisition modes. Available values:                                                              |
|                            |              |                               | | SINGLE: standard mode                                                                             |
|                            |              |                               | | ACCUMULATION: accumulate frames                                                                   |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|exposureTime                |R/W           |DevDouble                      |Exposure time (in ms) (can be changed during Live view (via Start command))                          |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|latencyTime                 |R/W:          |DevDouble                      |Latency time (in ms)                                                                                 |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|frameRate                   |R/W           |DevDouble                      |Compute the latency thanks to the current exposureTime                                               |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|roiX                        |R             |DevUShort                      |Region of Interest . (Origin X)                                                                      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|roiY                        |R             |DevUShort                      |Region of Interest . (Origin Y)                                                                      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|roiWidth                    |R             |DevUShort                      |Region of Interest . (Width)                                                                         |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|roiHeight                   |R             |DevUShort                      |Region of Interest . (Height)                                                                        |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|binningH                    |R             |DevUShort                      |Horizontal binning                                                                                   |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|binningV                    |R             |DevUShort                      |Vertical binning                                                                                     |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|nbFrames                    |R/W           |DevLong                        |Number of frames to acquire (Forced to zero when acquisition is started by Start command)            |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|currentFrame                |R             |DevULong                       |Current acquired frame number                                                                        |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|fileGeneration              |W             |DevBoolean                     |Enable/Disable the file saving                                                                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|fileFormat                  |W             |DevString                      |Set the saving file format (available values: NXS, EDF, HDF5, RAW )                                  |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|filePrefix                  |W             |DevString                      |Prefix name of the saved file (underscore is automatically added at the end)                         |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|fileTargetPath              |W             |DevString                      |Target path for the saved file                                                                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|fileNbFrames                |W             |DevLong                        |Number of frame per file                                                                             |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|image                       |R             | | Depends on some parameters. |Last acquired image                                                                                  |
|                            |              | | available types:            |                                                                                                     |
|                            |              | | DevUChar                    |                                                                                                     |
|                            |              | | DevUShort                   |                                                                                                     |
|                            |              | | DevULong                    |                                                                                                     |
|                            |              | | DevLong                     |                                                                                                     |
|                            |              | | DevFloat                    |                                                                                                     |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|log                         |R             |Array of DevString             |Logs from Tango and Lima                                                                             |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|info                        |R             |Array of DevString             |Informations on version of LimaCore and plugins                                                      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+

Optionnal attributes (depend on config)
---------------------------------------
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|  Attribute name            |  Read/Write  |  Type                         |  Description                                                                                        |
+============================+==============+===============================+=====================================================================================================+
|shutterMode                 |R/W           |DevString                      | | Shutter modes. Available values:                                                                  |
|                            |              |                               | | MANUAL: opened and closed manually by OpenShutter and CloseShutter commands                       |
|                            |              |                               | | AUTO_FRAME: the shutter output signal is activated for each frame of a sequence                   |
|                            |              |                               | | AUTO_SEQUENCE: the shutter output signal is activated for the whole sequence                      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|shutterState                |R             |DevString                      |State of the Shutter (in case of MANUAL mode)                                                        |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|shutterOpenTime             |R/W           |DevDouble                      | | Delay (ms) between the output shutter trigger and the beginning of the acquisition,               |
|                            |              |                               | | if not null the shutter signal is set on before the acquisition is started.                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|shutterCloseTime            |R/W           |DevDouble                      | | Delay (ms)  between the shutter trigger and the end of the acquisition,                           |
|                            |              |                               | | if not null the shutter signal is set on before the end of the acquisition.                       |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|exposureAccTime             |R/W           |DevDouble                      |Accumulation exposure time (ms)                                                                      |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+
|currentAccFrame             |R             |DevULong                       |Current accumulation acquired frame                                                                  |
+----------------------------+--------------+-------------------------------+-----------------------------------------------------------------------------------------------------+

Commands
--------
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|  Command name              |  Arg. in                                  |  Arg. out                           |  Description                                                                                        |
+============================+===========================================+=====================================+=====================================================================================================+
|Init                        |DevVoid                                    |DevVoid                              |Init the device                                                                                      |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|State                       |DevVoid                                    |DevLong                              |Return the device state                                                                              |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Status                      |DevVoid                                    |DevString                            |Return the device state as a string                                                                  |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Prepare                     |DevVoid                                    |DevVoid                              |Prepare the acquisition (Apply parameters like bin/roi/exposure/.. & allocate buffers & ...)         |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Snap                        |DevVoid                                    |DevVoid                              |Starts the acquisition of a number of frames equal to 'nbFrames' attribute value.                    |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Start                       |DevVoid                                    |DevVoid                              | | Starts a "video/live" acquisition of an infinite number of frames.                                |
|                            |                                           |                                     | | In this mode, the frame loss is allowed and not signaled as FAULT in the device state             |
|                            |                                           |                                     | | It is not allowed to generate files in this mode.                                                 |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|Stop                        |DevVoid                                    |DevVoid                              |Stop current acquisition/video.                                                                      |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|SetROI                      | | DevVarULongArray:                       |DevVoid                              | | Define a Region of Interest . (OriginX, OriginY, Width, Height)                                   |
|                            | | [origin_x, origin_y, width, height]     |                                     | | Roi and Binning are associated.                                                                   |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|SetBinning                  |DevVarULongArray: [bin_x, bin_y]           |DevVoid                              |Define a binning Horizontal (x) & Vertical (y) for the image.                                        |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ResetBinning                |DevVoid                                    |DevVoid                              |Use the binning Horizontal=1 & Vertical=1 of the detector according to current Roi.                  |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ResetROI                    |DevVoid                                    |DevVoid                              |Use the full frame of the detector according to current Binning.                                     |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|GetAttributeAvailableValues |DevString: Attribute name                  |DevVarStringArray: available values  |Return available values of the given String attribute                                                |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|GetAvailableCapabilities    |DevVoid                                    |DevVoid                              |Return available capabilities of the camera (eg: DetInfo, Bin, Roi ...)                              |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ResetFileIndex              |DevVoid                                    |DevVoid                              |Reset the file index                                                                                 |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|ReloadROI                   |DevVoid                                    |DevVoid                              |This command allows reloading the last ROI values set using the SetROI command.                      |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+

Optionnal commands (depend on config)
-------------------------------------
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|  Command name              |  Arg. in                                  |  Arg. out                           |  Description                                                                                        |
+============================+===========================================+=====================================+=====================================================================================================+
|OpenShutter                 |DevVoid                                    |DevVoid                              |Open the shutter (only if shutterMode is MANUAL)                                                     |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
|CloseShutter                |DevVoid                                    |DevLong                              |Close the shutter (only if shutterMode is MANUAL)                                                    |
+----------------------------+-------------------------------------------+-------------------------------------+-----------------------------------------------------------------------------------------------------+
