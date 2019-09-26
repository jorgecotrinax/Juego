#pragma once
#include"JUGADOR.h"
#include"MAPA.h"
#include "ListaGenerica.h"
#include "Enemigos.h"
namespace JuegoForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FORMULARIO
	/// </summary>
	public ref class FORMULARIO : public System::Windows::Forms::Form
	{
	public:
		FORMULARIO(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			jugador = new JUGADOR();
			tecla = DIRECCION::NINGUNO;
			mapa = new MAPA();
			jugador->cambiar_imagen("robot.png");
			bloque_f = Image::FromFile("muro.png");
			BalasVolando = new ListaGenerica<Bala>();
			ColorBalas = gcnew SolidBrush(Color::Red);

			ListaEnemigos = new ListaGenerica<Enemigos>();
			IntervaloTiempo = BugForm = 0;
			I = 1;
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FORMULARIO()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		Random r;
		JUGADOR* jugador;
		DIRECCION tecla;
		Image^ bloque_f;
		MAPA* mapa;
		ListaGenerica<Bala>* BalasVolando;
		SolidBrush^ ColorBalas;
		/// <summary>
		/// Variable del diseñador necesaria.
		int IntervaloTiempo;
		int I;
		int BugForm;
		ListaGenerica<Enemigos>* ListaEnemigos;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FORMULARIO::timer1_Tick);
			// 
			// FORMULARIO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1307, 695);
			this->Name = L"FORMULARIO";
			this->Text = L"FORMULARIO";
			this->Load += gcnew System::EventHandler(this, &FORMULARIO::FORMULARIO_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FORMULARIO::FORMULARIO_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FORMULARIO_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		ListaEnemigos->addNodo(new Enemigos(r.Next(55, 620), r.Next(55, 620)));
		//while (I == 1)
		//{
		jugador->recogerBala(new Bala());
		jugador->recogerBala(new Bala());
		//I--;
		//}

		//ListaEnemigos->addNodo(new Enemigos(r.Next(55, 620), r.Next(55, 620)));
		//ListaEnemigos->addNodo(new Enemigos(r.Next(55, 620), r.Next(55, 620)));
		cout << "ENemigos" << ListaEnemigos->returnSize() << endl;
		cout << "Municiones" << jugador->CuantasBalas() << endl;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		cout << "Balas en el aire: " << BalasVolando->returnSize() << endl;
		IntervaloTiempo += timer1->Interval; //100 milisegundos
		if (IntervaloTiempo % 5000 == 0)
		{
			//Rectangle ^PilaSuelo = gcnew Rectangle(100, 100, 50, 50);
		}
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);

		jugador->mover(bg->Graphics, tecla);
		mapa->pintar(bg->Graphics, bloque_f);
		if (BalasVolando->returnSize() > 0)
		{
			BalasVolando->moverTodasBalas(bg->Graphics, ColorBalas);
		}
		if (ListaEnemigos->returnSize() > 0)
		{
			ListaEnemigos->moverTodosEnemigos(bg->Graphics, ColorBalas);
		}
		//cout << "Jugador en X: " << jugador->getX() << "\t Jugador Y:" << jugador->getY();
		bg->Render(gr);
		delete gr;
		delete bc;
		delete bg;
	}
	private: System::Void FORMULARIO_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		tecla = DIRECCION::NINGUNO;
		switch (e->KeyCode)
		{
		case Keys::Up:
			tecla = DIRECCION::ARRIBA;
			break;

		case Keys::Down:
			tecla = DIRECCION::ABAJO; break;
		case Keys::Left:
			tecla = DIRECCION::IZQUIERDA; break;
		case Keys::Right:
			tecla = DIRECCION::DERECHA; break;

		case Keys::Space:
				if (jugador->CuantasBalas() > 0)
				{

					Bala* nuevaBala = jugador->dispararBala();
					nuevaBala->LiberarBala(jugador->getOrientacion(), jugador->getX(), jugador->getY());
					BalasVolando->addNodo(nuevaBala);			//delete nuevaBala;

				}
				break;
			
		default: break;
		}
		jugador->agregar_direccion(tecla);
	}
};
}
