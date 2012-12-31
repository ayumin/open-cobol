using System;
using System.Diagnostics;
using Gtk;

public partial class MainWindow: Gtk.Window
{	
	public string _Prgm;
	public string _WorkingDir;
	public string _Switches;
	public MainWindow (): base (Gtk.WindowType.Toplevel)
	{
		Build ();
		//Initialize the defaults
		FormInitialize();
	}
	
	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	/// <summary>
	/// Forms the initialize.
	///    Initializes the defaults
	/// </summary>
	private void FormInitialize ()
	{
		chkDefault.Activate ();
		chkNoTrunc.Activate ();
		lblOS.Text=OCiCMono.Util.GetOS();
		nbOutput.Page=0;
		txtProgram.HasFocus=true;
	}

	protected void OnFilechooserbutton1SelectionChanged (object sender, EventArgs e)
	{
		string file = filechooserbutton1.Filename.ToString ();
		string[] sFile = file.Split ('\\');
		int count = -1;
		foreach (string s in sFile) {
			count++;
		}

		txtProgram.Text=file;
	}

	protected void OnBtnCompileClicked (object sender, EventArgs e)
	{
		string temp = txtProgram.Text;
		if (temp == "") {
			OCiCMono.MessageBox.Show ("You must select a source file.");
		}
		else
		{

			SetSwitches();
			txtOutput.Buffer.Text = ExecuteCompile();
			string[] cmd = _Prgm.Split ('.');
			// update debug tabs
			txtCfile.Buffer.Text = OCiCMono.Util.GetFile(cmd[0] +".c", _WorkingDir);
			txtCLfile.Buffer.Text = OCiCMono.Util.GetFile(cmd[0] +".c.h", _WorkingDir);
			txtCLHfile.Buffer.Text = OCiCMono.Util.GetFile(cmd[0] +".c.l.h", _WorkingDir);
			if (txtOutput.Buffer.Text == "SUCCESS!" && chkExecute.Active)
			{
				OCiCMono.Util.Execute (cmd[0], txtPgmParams.Text, _WorkingDir);
			}
		}
	}

	/// <summary>
	/// Sets the switches as per checked values
	/// note: if DEFAULT is checked then no switch is set
	/// </summary>
	private void SetSwitches ()
	{
		_Switches = "";
		if (chkBS2000.Active) { 
			_Switches = _Switches + "std=bs2000 ";
		}
		if (chkCobol85.Active) { 
			_Switches = _Switches + "std=cobol85 ";
		}
		if (chkCobol2k2.Active) { 
			_Switches = _Switches + "std=cobol2002 ";
		}
		if (chkIBM.Active) { 
			_Switches = _Switches + "std=ibm ";
		}
		if (chkMicroFocus.Active) { 
			_Switches = _Switches + "std=mf ";
		}
		if (chkMVS.Active) { 
			_Switches = _Switches + "std=mvs ";
		}

		// set the compiler switches
		if (chkDebug.Active) { 
			_Switches = _Switches + "-debug -g ";
		}
		if (chkDll.Active != true) { 
			_Switches = _Switches + "-x ";
		}
		if (chkNoTrunc.Active) { 
			_Switches = _Switches + "-fnotrunc ";
		}
		if (chkTraceYN.Active && chkTraceAll.Active != true) { 
			_Switches = _Switches + "-ftrace ";
		}
		if (chkTraceAll.Active) { 
			_Switches = _Switches + "-ftraceall ";
		}
		//check additional switches
		if (txtAddSwitch.Text != "") {
			_Switches = _Switches + txtAddSwitch.Text + " ";
		}
		//check copy/include path
		if (txtCopyInc.Text != "") {
			_Switches = _Switches + "-I " + txtCopyInc.Text + " ";
		}
		//check Library
		if (txtLibrary.Text != "") {
			_Switches = _Switches + "-L " + txtLibrary.Text + " ";
		}
	}

	private string ExecuteCompile ()
	{
				int count = -1;
		//Parse for working dir and path
		string[] temp = txtProgram.Text.Split('\\');
		foreach( string s in temp)
		{
			count++;
		}

		_Prgm=temp[count];
		int iMyLen = txtProgram.Text.Length - _Prgm.Length; //Or whatever length you want...
		_WorkingDir = txtProgram.Text.Substring(0,iMyLen);
		//set command line
		string _cobc = " " +  _Switches + "-g " + _Prgm;
		return OCiCMono.Util.Compile ("cobc", _cobc, _WorkingDir );
	}

	protected void OnHelpAction1Activated (object sender, EventArgs e)
	{
	}


	protected void OnAboutActionActivated (object sender, EventArgs e)
	{
		string msg = "OCIC originally procduced by Gary Cuttler. \n";
		msg = msg + "This version is created by Damon Hermann. \n";
		OCiCMono.MessageBox.Show (msg);
	}
	}


