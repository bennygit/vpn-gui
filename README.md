# vpn-gui

_A simple vpn status indicator (gtk+3) using a custom made openconnect
script to connect to university vpn server._

## Depedencies

* GTK+3 toolkit (http://www.gtk.org/)
* A script that cares about your vpn connection.

## Compiling
Run make.

## Installing
Just copy the vpn-gui executable created by calling make wherever you like.

## Using
Run vpn-gui. The script needed to controle the vpn connection is not included.
Use your own one. 
The script's patch is hard coded into the main C file (vpn-gui.c).


## Thanks
Thanks to Calvin Morrison. His mocicon application teached me how to write gtk+
applets/indicators. If you use moc(http://moc.daper.net/) as music player you may 
like his mocicon indicator (http://mocicon.sourceforge.net/).

## License
Licensed under the MIT license. License is included in the LICENSE file.

