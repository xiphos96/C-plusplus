using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace TestShape
{
	/// <summary>
	/// Form1에 대한 요약 설명입니다.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private AxShape.AxCShape axCShape1;
		private System.Windows.Forms.ComboBox cboType;
		private System.Windows.Forms.Label lblMessage;
		private System.Windows.Forms.Button btnChange;
		private System.Windows.Forms.Button btnShapeType;
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Windows Form 디자이너 지원에 필요합니다.
			//
			InitializeComponent();

			//
			// TODO: InitializeComponent를 호출한 다음 생성자 코드를 추가합니다.
			//
		}

		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form 디자이너에서 생성한 코드
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다.
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
		/// </summary>
		private void InitializeComponent()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
			this.axCShape1 = new AxShape.AxCShape();
			this.cboType = new System.Windows.Forms.ComboBox();
			this.btnChange = new System.Windows.Forms.Button();
			this.lblMessage = new System.Windows.Forms.Label();
			this.btnShapeType = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.axCShape1)).BeginInit();
			this.SuspendLayout();
			// 
			// axCShape1
			// 
			this.axCShape1.Enabled = true;
			this.axCShape1.Location = new System.Drawing.Point(40, 48);
			this.axCShape1.Name = "axCShape1";
			this.axCShape1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axCShape1.OcxState")));
			this.axCShape1.Size = new System.Drawing.Size(232, 200);
			this.axCShape1.TabIndex = 0;
			this.axCShape1.ClickOut += new AxShape._IShapeEvents_ClickOutEventHandler(this.OnClickOut);
			this.axCShape1.ClickIn += new AxShape._IShapeEvents_ClickInEventHandler(this.OnClickIn);
			// 
			// cboType
			// 
			this.cboType.Location = new System.Drawing.Point(320, 56);
			this.cboType.Name = "cboType";
			this.cboType.Size = new System.Drawing.Size(160, 20);
			this.cboType.TabIndex = 1;
			this.cboType.Text = "comboBox1";
			// 
			// btnChange
			// 
			this.btnChange.Location = new System.Drawing.Point(328, 208);
			this.btnChange.Name = "btnChange";
			this.btnChange.Size = new System.Drawing.Size(144, 23);
			this.btnChange.TabIndex = 2;
			this.btnChange.Text = "ChangeShape 메서드";
			this.btnChange.Click += new System.EventHandler(this.btnChange_Click);
			// 
			// lblMessage
			// 
			this.lblMessage.Location = new System.Drawing.Point(40, 280);
			this.lblMessage.Name = "lblMessage";
			this.lblMessage.Size = new System.Drawing.Size(440, 24);
			this.lblMessage.TabIndex = 3;
			this.lblMessage.Text = "이벤트";
			// 
			// btnShapeType
			// 
			this.btnShapeType.Location = new System.Drawing.Point(328, 136);
			this.btnShapeType.Name = "btnShapeType";
			this.btnShapeType.Size = new System.Drawing.Size(144, 23);
			this.btnShapeType.TabIndex = 4;
			this.btnShapeType.Text = "ShapeType 속성";
			this.btnShapeType.Click += new System.EventHandler(this.btnShapeType_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(536, 333);
			this.Controls.Add(this.btnShapeType);
			this.Controls.Add(this.lblMessage);
			this.Controls.Add(this.btnChange);
			this.Controls.Add(this.cboType);
			this.Controls.Add(this.axCShape1);
			this.Name = "Form1";
			this.Text = "Shape 컨트롤 테스트";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.axCShape1)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// 해당 응용 프로그램의 주 진입점입니다.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void Form1_Load(object sender, System.EventArgs e) {
			cboType.Items.Add("사각형");
			cboType.Items.Add("원형");
			cboType.Items.Add("삼각형");
			cboType.SelectedIndex = axCShape1.ShapeType;
		}

		private void OnClickIn(object sender, AxShape._IShapeEvents_ClickInEvent e) {
			lblMessage.Text = string.Format("Click In : ({0}, {1})", e.x, e.y);
		}

		private void OnClickOut(object sender, AxShape._IShapeEvents_ClickOutEvent e) {
			lblMessage.Text = string.Format("Click Out : ({0}, {1})", e.x, e.y);
		}

		private void btnShapeType_Click(object sender, System.EventArgs e) {
			axCShape1.ShapeType = (short)cboType.SelectedIndex;
		}

		private void btnChange_Click(object sender, System.EventArgs e) {
			axCShape1.ChangeShape((short)cboType.SelectedIndex);
		}
	}
}
