#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double roomWidth, roomLenght, roomHeight, wallpaperWidth, wallpaperLenght;

	cout << "Введите ширину комнаты: "; cin >> roomWidth; //while (cout << "Введите ширину комнаты: " && !(cin >> roomWidth))
	cout << "Введите длину комнаты: "; cin >> roomLenght;
	cout << "Введите высоту комнаты: "; cin >> roomHeight;
	cout << "Введите ширину рулона: "; cin >> wallpaperWidth;
	cout << "Введите длину рулона: "; cin >> wallpaperLenght;

	if (!cin)
	{
		cerr << "Ошибка: Некорректный ввод! " << endl;
		return 0;
	}

	if (roomHeight > wallpaperLenght)
	{
		cout << "Ошибка! Вы ввели данные некорректно, длина рулона меньше высоты комнаты. Высота комнаты должна быть меньше либо равно длине рулона!";
		return 0;
	}
	if (roomHeight <= 0 || roomLenght <= 0 || roomWidth <= 0 || wallpaperLenght <= 0 || wallpaperWidth <= 0)
	{
		cout << "Ошибка! Вы ввели данные некорректно, одно или несколько данных меньше или равно нулю, все значения должны быть больше нуля!";
		return 0;
	}

	double wallSurfaceArea = (2 * (roomLenght * roomHeight + roomWidth * roomHeight));
	double squareOfRoll = wallpaperLenght * wallpaperWidth;
	double polos = floor(wallpaperLenght / roomHeight);
	double d_polos = polos * wallpaperWidth;
	double rollsNeeded = (ceil((roomLenght + roomWidth) * 2 / d_polos));
	double obsh_square = squareOfRoll * rollsNeeded;
	double remainOfRolls = (1 - (wallSurfaceArea / obsh_square)) * 100;

	cout << "Для поклейки стен комнаты понадобиться " << rollsNeeded << "рулонов обоев." << "\n";
	cout << "После поклейки обоев останется " << remainOfRolls << "% обоев.";

	return 0;
}