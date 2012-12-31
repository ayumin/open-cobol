using System;
using Gtk;
namespace OCiCMono
{
	public class MessageBox
	{
		public MessageBox ()
		{
		}
		public static void Show(string Msg)
		{
			MessageDialog md = new MessageDialog (null, DialogFlags.Modal, MessageType.Info, ButtonsType.Ok, Msg);
			md.SetPosition (WindowPosition.CenterAlways);
			md.Run ();
			md.Destroy();
		}
	}
}

