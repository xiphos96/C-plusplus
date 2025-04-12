using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace CustClient
{
	/// <summary>
	/// Form1에 대한 요약 설명입니다.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private AxCustInfo.AxCCustomer axCCustomer1;
		private System.Windows.Forms.Button btnGetCustInfo;
		private System.Windows.Forms.Label lblResult;
		private System.Windows.Forms.Button btnChangeCustInfo;
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
			this.axCCustomer1 = new AxCustInfo.AxCCustomer();
			this.btnGetCustInfo = new System.Windows.Forms.Button();
			this.lblResult = new System.Windows.Forms.Label();
			this.btnChangeCustInfo = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.axCCustomer1)).BeginInit();
			this.SuspendLayout();
			// 
			// axCCustomer1
			// 
			this.axCCustomer1.Enabled = true;
			this.axCCustomer1.Location = new System.Drawing.Point(16, 24);
			this.axCCustomer1.Name = "axCCustomer1";
			this.axCCustomer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axCCustomer1.OcxState")));
			this.axCCustomer1.Size = new System.Drawing.Size(368, 208);
			this.axCCustomer1.TabIndex = 0;
			this.axCCustomer1.ChangedCustAddr += new AxCustInfo._ICustomerEvents_ChangedCustAddrEventHandler(this.axCCustomer1_ChangedCustAddr);
			this.axCCustomer1.ChangedCustName += new AxCustInfo._ICustomerEvents_ChangedCustNameEventHandler(this.axCCustomer1_ChangedCustName);
			this.axCCustomer1.ChangedCustTelno += new AxCustInfo._ICustomerEvents_ChangedCustTelnoEventHandler(this.axCCustomer1_ChangedCustTelno);
			// 
			// btnGetCustInfo
			// 
			this.btnGetCustInfo.Location = new System.Drawing.Point(392, 72);
			this.btnGetCustInfo.Name = "btnGetCustInfo";
			this.btnGetCustInfo.Size = new System.Drawing.Size(144, 23);
			this.btnGetCustInfo.TabIndex = 1;
			this.btnGetCustInfo.Text = "고객정보 가져오기";
			this.btnGetCustInfo.Click += new System.EventHandler(this.btnGetCustInfo_Click);
			// 
			// lblResult
			// 
			this.lblResult.Location = new System.Drawing.Point(32, 240);
			this.lblResult.Name = "lblResult";
			this.lblResult.Size = new System.Drawing.Size(504, 72);
			this.lblResult.TabIndex = 2;
			this.lblResult.Text = "결과";
			// 
			// btnChangeCustInfo
			// 
			this.btnChangeCustInfo.Location = new System.Drawing.Point(392, 144);
			this.btnChangeCustInfo.Name = "btnChangeCustInfo";
			this.btnChangeCustInfo.Size = new System.Drawing.Size(144, 23);
			this.btnChangeCustInfo.TabIndex = 3;
			this.btnChangeCustInfo.Text = "고객정보 변경";
			this.btnChangeCustInfo.Click += new System.EventHandler(this.btnChangeCustInfo_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(576, 341);
			this.Controls.Add(this.btnChangeCustInfo);
			this.Controls.Add(this.lblResult);
			this.Controls.Add(this.btnGetCustInfo);
			this.Controls.Add(this.axCCustomer1);
			this.Name = "Form1";
			this.Text = "CustInfo 컨트롤 사용 예제 프로그램";
			((System.ComponentModel.ISupportInitialize)(this.axCCustomer1)).EndInit();
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

		private void btnGetCustInfo_Click(object sender, System.EventArgs e) {
			lblResult.Text = string.Format("이름 : {0}\n주소 : {1}\n전화번호 : {2}", axCCustomer1.CustName, axCCustomer1.CustAddr, axCCustomer1.CustTelno);
		}

		private void btnChangeCustInfo_Click(object sender, System.EventArgs e) {
			axCCustomer1.CustName = "전병선";
			axCCustomer1.CustAddr = "주소";
			axCCustomer1.CustTelno = "전화번호";
		}

		private void axCCustomer1_ChangedCustName(object sender, AxCustInfo._ICustomerEvents_ChangedCustNameEvent e) {
			lblResult.Text = string.Format("이름 변경 : {0}", e.newName);
		}

		private void axCCustomer1_ChangedCustAddr(object sender, AxCustInfo._ICustomerEvents_ChangedCustAddrEvent e) {
			lblResult.Text = string.Format("주소 변경 : {0}", e.newAddr);
		}

		private void axCCustomer1_ChangedCustTelno(object sender, AxCustInfo._ICustomerEvents_ChangedCustTelnoEvent e) {
			lblResult.Text = string.Format("전화번호 변경 : {0}", e.newTelno);
		}
	}
}
