#pragma once

namespace sqlproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for registrationForm
	/// </summary>
	public ref class registrationForm : public System::Windows::Forms::Form
	{
	public:
		registrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~registrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Lebel1;
	protected:
	private: System::Windows::Forms::Label^ lebel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ Qalification_comboBox;
	private: System::Windows::Forms::TextBox^ textBox_name;
	private: System::Windows::Forms::TextBox^ textBox_college;
	private: System::Windows::Forms::ComboBox^ Grade_comboBox;





	private: System::Windows::Forms::Button^ Register;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Lebel1 = (gcnew System::Windows::Forms::Label());
			this->lebel2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Qalification_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_college = (gcnew System::Windows::Forms::TextBox());
			this->Grade_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Lebel1
			// 
			this->Lebel1->AutoSize = true;
			this->Lebel1->Location = System::Drawing::Point(72, 75);
			this->Lebel1->Name = L"Lebel1";
			this->Lebel1->Size = System::Drawing::Size(104, 16);
			this->Lebel1->TabIndex = 0;
			this->Lebel1->Text = L"Enter your name";
			// 
			// lebel2
			// 
			this->lebel2->AutoSize = true;
			this->lebel2->Location = System::Drawing::Point(72, 143);
			this->lebel2->Name = L"lebel2";
			this->lebel2->Size = System::Drawing::Size(136, 16);
			this->lebel2->TabIndex = 1;
			this->lebel2->Text = L"Enter your Qalification";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 197);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Last college";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 238);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Grade";
			// 
			// Qalification_comboBox
			// 
			this->Qalification_comboBox->FormattingEnabled = true;
			this->Qalification_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Under graduated", L"Graduated", L"PostGraduation" });
			this->Qalification_comboBox->Location = System::Drawing::Point(238, 143);
			this->Qalification_comboBox->Name = L"Qalification_comboBox";
			this->Qalification_comboBox->Size = System::Drawing::Size(142, 24);
			this->Qalification_comboBox->TabIndex = 4;
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(238, 75);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(142, 22);
			this->textBox_name->TabIndex = 5;
			// 
			// textBox_college
			// 
			this->textBox_college->Location = System::Drawing::Point(238, 197);
			this->textBox_college->Name = L"textBox_college";
			this->textBox_college->Size = System::Drawing::Size(142, 22);
			this->textBox_college->TabIndex = 6;
			// 
			// Grade_comboBox
			// 
			this->Grade_comboBox->FormattingEnabled = true;
			this->Grade_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"O+", L"O", L"A+", L"A", L"B+", L"B", L"C+",
					L"C"
			});
			this->Grade_comboBox->Location = System::Drawing::Point(238, 235);
			this->Grade_comboBox->Name = L"Grade_comboBox";
			this->Grade_comboBox->Size = System::Drawing::Size(142, 24);
			this->Grade_comboBox->TabIndex = 7;
			// 
			// Register
			// 
			this->Register->Location = System::Drawing::Point(212, 307);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(112, 37);
			this->Register->TabIndex = 8;
			this->Register->Text = L"Register me ";
			this->Register->UseVisualStyleBackColor = true;
			this->Register->Click += gcnew System::EventHandler(this, &registrationForm::Register_Click);
			// 
			// registrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(587, 455);
			this->Controls->Add(this->Register);
			this->Controls->Add(this->Grade_comboBox);
			this->Controls->Add(this->textBox_college);
			this->Controls->Add(this->textBox_name);
			this->Controls->Add(this->Qalification_comboBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lebel2);
			this->Controls->Add(this->Lebel1);
			this->Name = L"registrationForm";
			this->Text = L"registrationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

		String^ connectionstring = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=student;Integrated Security=True;";

		SqlConnection^ connection = gcnew SqlConnection(connectionstring);

		void EnsureConnectionOpen() {
			if (connection->State != ConnectionState::Open) {
				connection->Open();
			}
		}


	private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = textBox_name->Text;
		String^ qualification = safe_cast<String^>(Qalification_comboBox->SelectedItem);
		String^ college = textBox_college->Text;
		String^ grade = safe_cast<String^>(Grade_comboBox->SelectedItem);

		try {
			String^ insertQuery = "INSERT INTO student (name, qualification, last_college, grade) VALUES (@Name, @qualification, @college, @grade)";

			EnsureConnectionOpen();

			// Command creation
			SqlCommand^ command = gcnew SqlCommand(insertQuery, connection);

			// Add parameters
			command->Parameters->AddWithValue("@Name", name);
			command->Parameters->AddWithValue("@qualification", qualification);
			command->Parameters->AddWithValue("@college", college);
			command->Parameters->AddWithValue("@grade", grade);

			// Execute the query
			int rowsAffected = command->ExecuteNonQuery();

			

			// Inform the user about the success
			MessageBox::Show("Registration successful!");
		}
		catch (SqlException^ ex) {
			// Handle SQL exception
			MessageBox::Show("SQL Error: " + ex->Message);
		}
		catch (Exception^ ex) {
			// Handle other exceptions
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			// Close the connection
			connection->Close();
		}
	}
	
};
}
