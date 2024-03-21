#pragma once
#include "registrationForm.h"

#include "remove.h"

namespace sqlproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for base
	/// </summary>
	public ref class base : public System::Windows::Forms::Form
	{
	public:
		base(void)
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
		~base()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::Button^ newstudent;

	private: System::Windows::Forms::Button^ delete_student;
	private: System::Windows::Forms::Button^ Refress_button;


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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->newstudent = (gcnew System::Windows::Forms::Button());
			this->delete_student = (gcnew System::Windows::Forms::Button());
			this->Refress_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(130, 30);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(493, 276);
			this->listBox1->TabIndex = 0;
			// 
			// newstudent
			// 
			this->newstudent->Location = System::Drawing::Point(130, 396);
			this->newstudent->Name = L"newstudent";
			this->newstudent->Size = System::Drawing::Size(107, 23);
			this->newstudent->TabIndex = 1;
			this->newstudent->Text = L"New Student";
			this->newstudent->UseVisualStyleBackColor = true;
			this->newstudent->Click += gcnew System::EventHandler(this, &base::newstudent_Click);
			// 
			// delete_student
			// 
			this->delete_student->Location = System::Drawing::Point(545, 396);
			this->delete_student->Name = L"delete_student";
			this->delete_student->Size = System::Drawing::Size(107, 23);
			this->delete_student->TabIndex = 3;
			this->delete_student->Text = L"Remove  student";
			this->delete_student->UseVisualStyleBackColor = true;
			this->delete_student->Click += gcnew System::EventHandler(this, &base::delete_student_Click);
			// 
			// Refress_button
			// 
			this->Refress_button->Location = System::Drawing::Point(342, 313);
			this->Refress_button->Name = L"Refress_button";
			this->Refress_button->Size = System::Drawing::Size(75, 23);
			this->Refress_button->TabIndex = 4;
			this->Refress_button->Text = L"Refresh";
			this->Refress_button->UseVisualStyleBackColor = true;
			this->Refress_button->Click += gcnew System::EventHandler(this, &base::Refress_button_Click);
			// 
			// base
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(726, 598);
			this->Controls->Add(this->Refress_button);
			this->Controls->Add(this->delete_student);
			this->Controls->Add(this->newstudent);
			this->Controls->Add(this->listBox1);
			this->Name = L"base";
			this->Text = L"base";
			this->ResumeLayout(false);

		}
#pragma endregion

		void PopulateStudentList()
		{
			try {
				String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=student;Integrated Security=True;";
				SqlConnection^ connection = gcnew SqlConnection(connectionString);
				connection->Open();

				String^ selectQuery = "SELECT* FROM student";
				SqlCommand^ command = gcnew SqlCommand(selectQuery, connection);
				SqlDataReader^ reader = command->ExecuteReader();

				// Clear existing items in ListBox
				listBox1->Items->Clear();

				// Populate ListBox with student names
				//while (reader->Read()) {
					//listBox1->Items->Add(reader->GetString(0));
				//}
				// 
				
				// Populate ListBox with student data
				 
				while (reader->Read()) {
					// Retrieve the ID as an integer
					int id = reader->GetInt32(0);
					// Retrieve other columns as strings
					String^ name = reader->GetString(1);
					String^ qualification = reader->GetString(2);
					String^ college = reader->GetString(3);
					String^ grade = reader->GetString(4);

					// Format the student data
					String^ studentData = String::Format("{0}, {1}, {2}, {3}, {4}", id, name, qualification, college, grade);
					listBox1->Items->Add(studentData);
				}
				reader->Close();
				connection->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}


	private: System::Void newstudent_Click(System::Object^ sender, System::EventArgs^ e) {
		registrationForm^ regist = gcnew registrationForm();
		regist->Show();
		
	}

	
     private: System::Void delete_student_Click(System::Object^ sender, System::EventArgs^ e) {
		 remove^ deletes = gcnew remove();
		 deletes->Show();
	 }    

     private: System::Void Refress_button_Click(System::Object^ sender, System::EventArgs^ e) {
		 PopulateStudentList();
      }
};
}
