using System;
using System.IO;
namespace OCiCMono
{
	public class Util
	{
		public Util ()
		{
		}

		/// <summary>
		/// Cobc this instance.
		/// </summary>
		/// <typeparam name='cmd'>
		/// The Command e.g. cobc.exe or cobc
		/// </typeparam>
		/// <typeparam name='value'>
		/// The parameters to pass in
		/// </typeparam>
		/// <typeparam name='workingPath'>
		/// Sets the working path for the command
		/// </typeparam>
		public static string Compile (string cmd, string value, string workingPath)
		{
			try
			{
				// create the ProcessStartInfo using "cmd" as the program to be run,
				// and "/c " as the parameters.
				// Incidentally, /c tells cmd that we want it to execute the command that follows,
				// and then exit.
				System.Diagnostics.ProcessStartInfo procStartInfo =
					new System.Diagnostics.ProcessStartInfo(cmd , value );
				
				// The following commands are needed to redirect the standard output.
				// This means that it will be redirected to the Process.StandardOutput StreamReader.
				procStartInfo.WorkingDirectory = workingPath;
				procStartInfo.RedirectStandardOutput = true;
				procStartInfo.RedirectStandardError = true;
				procStartInfo.LoadUserProfile = true;
				procStartInfo.UseShellExecute = false;
				// Do not create the black window.
				procStartInfo.CreateNoWindow = true;
				// Now we create a process, assign its ProcessStartInfo and start it
				System.Diagnostics.Process proc = new System.Diagnostics.Process();
				
				proc.StartInfo = procStartInfo;
				
				proc.Start();
				// Get the output into a string
				string result = proc.StandardOutput.ReadToEnd();
				string error = proc.StandardError.ReadToEnd();
				// Display the command output.
				if (error == "")
				{
					return "SUCCESS!";
				}
				else
				{
					return(error);
				}
			}
			catch (Exception objException)
			{
				return (objException.Message);
			}
		}

		/// <summary>
		/// Execute the specified cmd, value and workingPath.
		/// This will show the cmdline window
		/// </summary>
		/// <param name='cmd'>
		/// Cmd.
		/// </param>
		/// <param name='value'>
		/// Value.
		/// </param>
		/// <param name='workingPath'>
		/// Working path.
		/// </param>
		public static void Execute (string cmd, string value, string workingPath)
		{
			try
			{
				// create the ProcessStartInfo using "cmd" as the program to be run,
				// and "/c " as the parameters.
				// Incidentally, /c tells cmd that we want it to execute the command that follows,
				// and then exit.

				if ( GetOSid() == "1" )
				{
					cmd = workingPath + "\\" + cmd + ".exe";

				}
				else
				{
					cmd = workingPath + "/" + cmd ;
				}
				System.Diagnostics.ProcessStartInfo procStartInfo =
					new System.Diagnostics.ProcessStartInfo(cmd , value );
				
				// The following commands are needed to redirect the standard output.
				// This means that it will be redirected to the Process.StandardOutput StreamReader.
				procStartInfo.WorkingDirectory = workingPath;
				procStartInfo.RedirectStandardOutput = false;
				procStartInfo.RedirectStandardError = false;
				procStartInfo.LoadUserProfile = true;
				procStartInfo.UseShellExecute = false;
				// Do not create the black window.
				procStartInfo.CreateNoWindow = false;
				// Now we create a process, assign its ProcessStartInfo and start it
				System.Diagnostics.Process proc = new System.Diagnostics.Process();
				
				proc.StartInfo = procStartInfo;
				
				proc.Start();
			}
			catch (Exception objException)
			{
				OCiCMono.MessageBox.Show (objException.Message);
			}
		}

		public static string GetOS ()
		{
			string msg1 = "<b>This is a Windows operating system.</b>";
			string msg2 = "This is a Unix operating system.</b>";
			string msg3 = "<b>ERROR: This platform identifier is invalid.</b>";
			
			OperatingSystem os = Environment.OSVersion;
			PlatformID     pid = os.Platform;
			switch (pid) 
			{
			case PlatformID.Win32NT:
			case PlatformID.Win32S:
			case PlatformID.Win32Windows:
			case PlatformID.WinCE:
				return msg1;
			
			case PlatformID.Unix:
				return msg2;
			
			default:
				return msg3;
			
			}
		}

		public static string GetOSid ()
		{
			string msg1 = "1";
			string msg2 = "2";
			string msg3 = "<b>ERROR: This platform identifier is invalid.</b>";
			
			OperatingSystem os = Environment.OSVersion;
			PlatformID     pid = os.Platform;
			switch (pid) 
			{
			case PlatformID.Win32NT:
			case PlatformID.Win32S:
			case PlatformID.Win32Windows:
			case PlatformID.WinCE:
				return msg1;
				
			case PlatformID.Unix:
				return msg2;
				
			default:
				return msg3;
				
			}
		}

		public static string GetFile (string file, string sPath)
		{
			try{

				string filePath = "";
				if ( GetOSid() == "1" )
				{
					filePath = sPath + "\\" + file;

				}
				else
				{
					filePath = sPath + "/" + file ;
				}
				StreamReader streamReader = new StreamReader(filePath);
				string text = streamReader.ReadToEnd();
				streamReader.Close();
				return text;
			}
			catch (Exception e)
			{
				return e.Message;
			}
		}
	}

}

