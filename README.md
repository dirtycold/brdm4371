# brdm4371
Example Driver 
--------------

*brdm4371 has no meaning and is random but ordered to look like
a typical device name, if it matches anything real that is
an accident*

Nothing of value here, just an example of using the overlays on
Raspberry Pi for a simple plaform driver.

To use:

1. upload brdm4371-overlay.dtb to /boot/overlays/ on the pi.
2. Add the line
	`dtoverlay=brdm4371`
   to your `/boot/config.txt`
3. reboot
4. upload `brdm4371.ko` to pi, and run
	`insmod ./brdm4371.ko`


It doesn't do anything but put a few messages in the kmsg log.


