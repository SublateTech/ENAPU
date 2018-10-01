#include "menu.h"
#include "keyboard.h"
#include "scrollerh.h"
#include "scrollerv.h"
#include "scroller.h"




Menu::Menu()
{
	
	
//	Console con;
}

Menu::Exec(int Term)
{
	if (!Sql.Verifica())
		return 0;

	
	Terminal = Term;
	con.Terminal = Term;
	//Window wMenu(1 , 1 , 50 , 25 );
	Inputs  Kbd ;

	//con.vm_setmode(2);
	
//	if (Terminal == 1)
//	 {
		do      {
			
			system("cls");
			nKey = -1;
						
			con.vm_attrib(vm_mkcolor(DARKGRAY, BLACK));
			con.cls();
			//con.vm_frame(1 , 1 , 50 , 25 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_DOUBLE);
			con.gotoxy(0, 0);

			if (Terminal == 1)
			{
				con.write("\tMENU PRINCIPAL\n\n");
				con.write("\t  UBICACIONES\n");
			}
			con.write("1. Contenedores \n");
			con.write("2. Carga Fraccionada\n");
			con.write("3. Carga Rodante\n");
			if (Terminal == 1)
			{
			con.write("\t  TAREAS\n");
			}
			//con.write("4. Atend.Descarga\n");
			//con.write("5. Atend.Embarque\n");
			
			if (Terminal == 1)
			{
			con.write("\t  BALANZA\n");
			}
			con.write("6. Terminal Almacen.\n");
			con.write("7. Terminal Portuario\n");
			if (Terminal == 1)
			{
			con.write("\t  TABLAS\n");
			}
			con.write("8. Tipo Van\n");
			con.write("9. Condicion Van\n");
			con.write("10. Estado Van\n");
			con.write("11. Equipos/Accesor.\n");
			con.write("12. Muelles/Amarrad.\n");
			if (Terminal == 1)
			{
			con.write("\t  CONSULTAS\n");
			}
			con.write("13. Placa Vehicular\n");
			con.write("14. Brevete Chofer\n");
			//con.write("15. Mensajes\n");
			if (Terminal == 1)
			{
			con.write("0 . Salir\n");
			}
			con.write("Elija Opcion:");
			
			Kbd.gettext(Seleccion,2);

			nKey = atoi(Seleccion);
			switch (nKey)
				{
				case 1:
					{
					Ubicacion_Vanes MyVanes (Sql.dbproc, con);
					MyVanes.Execute(Terminal);
					nKey=-1;
					break;
					}
				case 2:
					{
					Carga_Fraccionada MyCarga (Sql.dbproc, con);
					MyCarga.Execute(Terminal);
					break;
					}
				case  3:
					{
					Carga_Rodante MyRodante(Sql.dbproc,con);
					MyRodante.Execute(Terminal);
					break;
					}
				case  4:
					{
					Descarga_Contenedores MyDescarga (Sql.dbproc, con);
					MyDescarga.Execute();
					break;
					}
				case 5:
					{
					Embarque_Contenedores MyEmbarque (Sql.dbproc, con);
					MyEmbarque.Execute();
					break;
					}

				case 6:
					{
					
					Terminal_Almacenamiento MyAlmacena (Sql.dbproc, con);
					MyAlmacena.Execute(Terminal);
					break;
					}
				case 7:
					{
					Terminal_Portuario MyPortuario (Sql.dbproc, con);
					MyPortuario.Execute(Terminal);
					break;
					}
				
				case 8:
					{
					Tipo_Contenedores TConten (Sql.dbproc, con);
					TConten.Execute(Terminal);
					break;
					}
				
				case 9:
					{
					Condicion_Contenedores CConten (Sql.dbproc, con);
					CConten.Execute(Terminal);
					break;
					}
				case 10:
					{
					Estado_Contenedores EstConten (Sql.dbproc, con);
					EstConten.Execute(Terminal);
					break;
					}
				case 11:
					{
					Equipos_Accesorios EqAcces (Sql.dbproc, con);
					EqAcces.Execute(Terminal);
					break;
					}
				case 12:
					{
					Muelles_Amarradores MueAma (Sql.dbproc, con);
					MueAma.Execute();
					break;
					}

				case 13:
					{
					Placas MyPlacas (Sql.dbproc,con);
					MyPlacas.Execute(Terminal);
					break;
					}
				case 14:
					{
					Chofer MyChofer (Sql.dbproc,con);
					MyChofer.Execute(Terminal);
					break;
					}
				case 15:
					{
					Mensajes MyMensaje (Sql.dbproc, con);
					MyMensaje.Execute();
					break;
					}
				
				case 0:
					Sql.Close_Db();
					con.vm_done();
					exit(0);
				case 27:
					
					con.strscrll("abcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyz", 2, 45, 7, 52);
					break;
				case 28:
					ScrollerV scrllv(2, 43, 5, 50,"abcdefghijklmnñopqrstuvwxyz", con);
					//con.strscrllh("abcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyz", 2, 43, 60);
					scrllv.Exec();
					break;
					//exit(0);
				}


	} while (1);
	/*
	}
	else
		{
			
			char Cadena[200];
			Scroller Lista;
			Lista.Init(1,1,17,20,con);
			Lista.SetTitle(" Menu Principal ");
			Lista.SetBorder(FRAME_SINGLE);

			con.vm_attrib(vm_mkcolor(LIGHTGRAY,BLACK));
			con.vm_clrscr();
			
			Lista.AddItem("1. Contenedores (Vanes)","1");
			Lista.AddItem("2. Carga Fraccionada","2");
			Lista.AddItem("3. Carga Rodante","3");
			Lista.AddItem("4. Atendidas Descarga Contenedores","4");
			Lista.AddItem("5. Atendidas Embarque Contenedores","5");
			Lista.AddItem("6. Terminal de Almacenamiento","6");
			Lista.AddItem("7. Terminal de Portuario","7");
			Lista.AddItem("8. Tipo Van","8");
			Lista.AddItem("9. Condicion Van","9");
			Lista.AddItem("10. Estado Van","10");
			Lista.AddItem("11. Equipos/Accesorios","11");
			Lista.AddItem("12. Muelles/Amarradores","12");
			Lista.AddItem("13. Placa Vehicular","13");
			Lista.AddItem("14. Brevete Chofer","14");
			Lista.AddItem("15. Mensajes","15");
			

			Lista.Show();
			Lista.Display();
			Lista.Finish();
		}*/
return 0;
}