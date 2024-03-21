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
	/// Summary for remove
	/// </summary>
	public ref class remove : public System::Windows::Forms::Form
	{
	public:
		remove(void)
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
		~remove()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ delete_student;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Enter_id;

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
			this->delete_student = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Enter_id = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// delete_student
			// 
			this->delete_student->Location = System::Drawing::Point(288, 186);
			this->delete_student->Name = L"delete_student";
			this->delete_student->Size = System::Drawing::Size(75, 23);
			this->delete_student->TabIndex = 0;
			this->delete_student->Text = L"Delete this student";
			this->delete_student->UseVisualStyleBackColor = true;
			this->delete_student->Click += gcnew System::EventHandler(this, &remove::delete_student_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(241, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Id";
			// 
			// Enter_id
			// 
			this->Enter_id->Location = System::Drawing::Point(308, 86);
			this->Enter_id->Name = L"Enter_id";
			this->Enter_id->Size = System::Drawing::Size(100, 22);
			this->Enter_id->TabIndex = 2;
			// 
			// remove
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 412);
			this->Controls->Add(this->Enter_id);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->delete_student);
			this->Name = L"remove";
			this->Text = L"remove";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void DeleteStudent(String^ studentID)
		{
			try {
				String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=student;Integrated Security=True;";
				SqlConnection^ connection = gcnew SqlConnection(connectionString);
				connection->Open();

				String^ deleteQuery = "DELETE FROM student WHERE id = @ID";
				SqlCommand^ command = gcnew SqlCommand(deleteQuery, connection);
				command->Parameters->AddWithValue("@ID", studentID);

				int rowsAffected = command->ExecuteNonQuery();
				if (rowsAffected > 0) {
					MessageBox::Show("Student deleted successfully!");
				}
				else {
					MessageBox::Show("No student found with the provided ID.");
				}

				connection->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}

	private: System::Void delete_student_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ studentID = Enter_id->Text;
		// Call DeleteStudent method with provided student ID
		DeleteStudent(studentID);
	}
	};
}
