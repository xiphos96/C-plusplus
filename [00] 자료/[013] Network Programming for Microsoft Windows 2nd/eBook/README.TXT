___________________________________________________________________

                              README

                               for

                	Microsoft Press eBooks	

            Copyright (c) 2002 by Microsoft Corporation

                       All Rights Reserved
___________________________________________________________________

README CONTENTS
 - EBOOK COMPONENTS
     - eBook
     - Setup
     - Microsoft Internet Explorer 5.5
 - SYSTEM REQUIREMENTS
     - Minimum System Requirements
     - Recommended System Requirements	
 - TECHNICAL SUPPORT FOR MICROSOFT PRESS PRODUCTS
   - Self-Help Tools Available
   - To Speak With a Microsoft Technical Support Engineer
   - Worldwide Support
 - KNOWN ISSUES
 - NOTES FOR SYSTEM ADMINISTRATORS
 - SEND FEEDBACK 





EBOOK COMPONENTS
================================

eBook 
---------------
Every effort has been made to ensure that the text of the eBook matches the text of the print version of the book as much as possible. Changes in formatting might have been made to the eBook version to ensure ease of readability on a screen.  Reprints of the paper version may include text updates not included in the eBook version of this title.

Setup
-----
Setup for this product will check the user's machine for required files, install required files and if a "Local" install is selected during setup, copy the eBook files to the user's machine.  

Microsoft Internet Explorer 5.5
-------------------------------
Important Note: Setup does not install the full version of Internet Explorer. Only the components required to view the eBook are installed. A full version of Internet Explorer 5.5 is located in the IE5SETUP subdirectory. Choose ie5setup.exe from this folder to launch the standard Internet Explorer 5.5 installation.

For up-to-date information on Internet Explorer please visit Microsoft's Internet Explorer Web site at the following URL:

    	http://www.microsoft.com/windows/ie/default.htm

Microsoft offers Standard No-Charge Support for retail versions** of Microsoft Internet Explorer as follows: 90 days no-charge support beginning with first contact with a Support Engineer.

To access Standard No-Charge Support for Microsoft Internet Explorer: 
	In the U.S.: (425) 635-7123. Monday-Friday, 6:00 AM - 6:00 PM, Pacific time, excluding holidays. 

	In Canada: (905) 568-4494. Monday-Friday, 8:00 AM - 8:00 PM, Eastern time, excluding holidays. 

**With the exception of the MSN online service, if your Microsoft product was preinstalled or distributed with your personal computer dedicated system or Windows CE-based device, or provided by an Internet Service Provider (ISP), the personal computer manufacturer, the device/system manufacturer, or ISP is responsible for providing your product support. Please contact the manufacturer or source of your Microsoft product for support information.



SYSTEM REQUIREMENTS
============

Minimum System Requirements
---------------------------
This eBook requires a system running:

* Pentium class with 166 megahertz (MHz) or higher processor

* Operating System required:
	Microsoft Windows 95 or
	Microsoft Windows 98 or
	Microsoft Windows NT 4 SP3 or higher
	Microsoft Windows 2000 Professional or
	Microsoft Windows 2000 Server or
	Microsoft Windows Millennium Edition

* Memory required:
	Microsoft Windows 95: 12 MB RAM or
	Microsoft Windows 98: 16 MB RAM or
	Microsoft Windows NT 4 SP6: 16 MB RAM
	Microsoft Windows 2000 Professional: 64 MB RAM
	Microsoft Windows 2000 Server: 64 MB RAM
	Microsoft Windows Millennium Edition: 64 MB RAM

* Disk Space required: 
   -To install and run an eBook from a network (network installation): 10 MB
   -To install and run an eBook to the hard drive (local installation): 20 - 31 MB
   -To install Microsoft Internet Explorer to the hard drive (local installation) and install and run an eBook from a network (network installation): 121 MB
   -To install Microsoft Internet Explorer to the hard drive (local installation) and install and run an eBook from a hard drive (local installation): 140 - 160 MB, depending on the size of the sample files, if locally installed.

Microsoft Internet Explorer 5.5 is included on the CD and will be installed on the user's machine automatically if necessary. The Internet Explorer setup has been configured to install the minimum necessary files and will not change the user's current settings or associations.

Recommended System Requirements
-------------------------------
The following system configuration is recommended for the best viewing experience of Microsoft Press eBooks:

	*Windows 98 or Windows 2000 (Professional, Server, or Me)
	*Pentium II (or similar) with 266 MHz or higher processor
	*64 MB RAM 
	*8X CD-ROM drive or faster
	*800x600 with high color (16-bit) display settings




TECHNICAL SUPPORT FOR MICROSOFT PRESS PRODUCTS
=========================================
This eBook was converted from the original print version of this title. For usability reasons, formatting changes may have been made to the content within the eBook. Microsoft offers technical support and services ranging from self-help tools to direct assistance with a Microsoft Technical Support Engineer. Note: The services listed below are available in the United States and Canada only (see Worldwide Support below).

Self-Help Tools Available
-------------------------
Support Online: You may look for the answer to your question online by visiting the Microsoft  Personal Online Support site. You can search by product, by typing in a specific question, or by  searching through Knowledge Base articles.  The Microsoft Personal Online Support site is available  at the following URL:

	http://support.microsoft.com/support/ 

Text corrections for Microsoft print books are available via Knowledge Base articles on the Microsoft Personal Online Support web site. To view all Knowledge Base articles visit the URL above, and type in key words for the appropriate title at the "Enter words for your search below" field.  Click "Go" and all articles relating to the particular title will appear.

To Speak With a Microsoft Technical Support Engineer
----------------------------------------------------
	Standard no-charge support for this product in the U.S.: (425) 635-7123. Monday-Friday, 6:00 AM - 6:00 PM, Pacific time, excluding holidays. 

	Standard no-charge support for this product in Canada: (905) 568-4494. Monday-Friday, 8:00 AM - 8:00 PM, Eastern time, excluding holidays. 

With the exception of the MSN online service, if your Microsoft Press product was preinstalled or distributed with your personal computer dedicated system or Windows CE-based device, or provided by an Internet Service Provider (ISP), the personal computer manufacturer, the device/system manufacturer, or ISP is responsible for providing your product support. Please contact the manufacturer or source of your Microsoft product for support information.

Worldwide Support
-----------------
To access support within locations outside of the United States or Canada, please visit the Microsoft Product Support directory at:

	http://support.microsoft.com/directory/default.asp

and choose the correct location from the drop-down box under the Worldwide Support directory.

	

KNOWN ISSUES
============
The following are known issues with the Microsoft HTML Help ActiveX Control version 1.2

*Printing may fail when you attempt to print a large section of the eBook.

*You must be an Administrator in order to install the HTML Help Installation and Update package (hhupd.exe) on a Windows NT system.

*HTML Help does not run on any version of Windows NT earlier than Windows NT 4.0.

*When using the highlighting feature in search (accessed via the HTML Help tool bar at: Options, Search Highlight On/Off) it is necessary to refresh when the highlighting feature has been turned on or off.

*When using Internet Explorer version 5.0 on a Windows 95, Windows 98 or Windows NT system on machines with a slower processor, HH errors may occur when loading pages.  It is recommended that machines with slower processors using Windows 95, Windows 98, or Windows NT download Internet Explorer 5.5 SP 1 or newer in order to resolve loading issues.


NOTES FOR SYSTEM ADMINISTRATORS
===============================
The following notes are intended for use by build masters and system administrators who are administering the setup for their organizations.

A few settings in the BONLINE.INI file within the root of the eBook provide options for the customization of dialogs and text for IE installation.   If you need to save disk space and bypass the IE setup bits, then make the following change:

[InternetExplorer]
RequireIE=1
RequiredIEVersionMajor=5
RequiredIEVersionMinor=0
TypeOfIEInstall=Web

When the change is made to install IE from the web,the user will see a message with the correct URL to install IE from.  All users  with Internet Explorer versions <5.0 will see the following dialog: 

"Setup requires a newer version of Internet Explorer than the one currently installed on this machine.  Please install it from http://www.microsoft.com/ie, and then run setup again."

SEND FEEDBACK
===================================
Tell us what you think!  If you have comments, questions, or ideas regarding Microsoft Press eBooks, please send them to the Microsoft Press ePublishing Team via:

    epublish@microsoft.com

For general feedback regarding Microsoft Press print books, send e-mail to 

    mspinput@microsoft.com   


Please note that product support is not offered through the above addresses. 



<end>
