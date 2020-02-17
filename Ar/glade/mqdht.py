import gi
import serial as ser
gi.require_version('Gtk','3.0')
from gi.repository import Gtk, GLib

arduino = ser.Serial('/dev/ttyUSB0', 9600)

class test_mqdht():
    def mqdht_destroy_cb (self, object, data=None):
        Gtk.main_quit()


def get_data(*args):
    data = arduino.readline()[:-2]

    hslppm = builder.get_object("hslppm")
    hslppm.set_text(str(data)[12:17])

    hslprcnt = builder.get_object("hslprcnt")
    hslprcnt.set_text(str(data)[7:12])

    hsltmp = builder.get_object("hsltmp")
    hsltmp.set_text(str(data)[2:7])

    hslhum = builder.get_object("hslhum")
    hslhum.set_text(str(data)[7:12])

    return True

builder = Gtk.Builder()
builder.add_from_file("mqdht.glade")
window = builder.get_object("mqdht")
window.show_all()

builder.connect_signals(test_dht())
GLib.idle_add(get_data)
Gtk.main()
