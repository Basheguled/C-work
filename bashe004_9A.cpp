//CSCI 1113 HW8
//Guled Bashe
//HW Problem 8B

#include <iostream>
using namespace std;

class color{
  private:
	int red, green, blue;
  public:
    color() //default constructor
		{
			red = 0;
			green = 0;
			blue = 0;
		}
	color(int r, int g, int b) //constructor with parameters
	{
		if(r > 255 || r < 0) //checks value of user input
		{                    //sets r, g, b to 0 if they are out of range
			cout << "Initialization:  component out of range. All components set to 0" << endl;
			red = 0;
			green = 0;
			blue = 0;
		}

		else if(g > 255 || g < 0)
		{
			cout << "Initialization: component out of range. All components set to 0" << endl;
			red = 0;
			green = 0;
			blue = 0;
		}

		else if(b > 255 || b < 0)
		{
			cout << "Initialization: component out of range. All components set to 0" << endl;
			red = 0;
			green = 0;
			blue = 0;
		}
    else //otherwise sets the private variables to the user input
    {
      red = r;
      green = g;
      blue = b;
    }
	}

	const int get_r()
	{
		return red;
	}

	const int get_g()
	{
		return green;
	}

	const int get_b()
	{
		return blue;
	}

	void set(int r, int g, int b) //sets object's colors to new numbers
  {
    color(r, g, b); //calls constructor
    if(r == 0 && g == 0 && b == 0)
			cout << "Components out of range. All components unchanged." << endl;
		else
		{
			red = r;
			blue = b;
			green = g;
		}
	}

	void invert() //flips value of color to the opposite
	{
		red = 255 - red;
		green = 255 - green;
    blue = 255 - blue;
	}

	void scale(double s)
	{
    double rs = red*s;
    double gs = green*s;
    double bs = blue*s;
		if(rs > 255 || rs < 0) //tests if scaling will set numbers out of range
		{                     //Does not change numbers if out of scale
			cout << "Scaling:  component out of range. All components unchanged" << endl;

		}

		else if(gs > 255 || gs < 0)
		{
			cout << "Scaling: component out of range. All components unchanged" << endl;

		}

		else if(bs > 255 || bs < 0)
		{
			cout << "Scaling: component out of range. All components unchanged" << endl;

		}
		else //otherwise scale numbers
		{
			red = rs;
			blue = bs;
			green = gs;
		}
	}

	/*void print(ostream& out) //output the final values formatted
	{
		out << "(" << red << ", " << green << ", " << blue << ")\n";
	}*/
  bool operator >(const color& lhs, const color& rhs)
  {
    return (lhs.red+lhs.blue+lhs.green) > (rhs.red+rhs.blue+rhs.green);
  }
  bool operator <(const color& lhs, const color& rhs)
  {
    return (lhs.red+lhs.blue+lhs.green) < (rhs.red+rhs.blue+rhs.green);
  }
  color operator +(color& c1, color& c2)
  {
    color c;
    c.red = c1.red + c2.red;
    c.green = c1.green + c2.green;
    c.blue = c1.blue + c2.blue;
    if(c.red > 255)
      c.red = 255;
    if(c.green > 255)
      c.green = 255;
    if(c.blue > 255)
      c.blue = 255;
    return c;
  }
  color operator -(color& c1, color& c2)
  {
    color c;
    c.red = c1.red - c2.red;
    c.green = c1.green - c2.green;
    c.blue = c1.blue - c2.blue;
    if(c.red < 0)
      c.red = 0;
    if(c.green < 0)
      c.green = 0;
    if(c.blue < 0)
      c.blue = 0;
    return c;
  }
  ostream& operator <<(ostream& out, const color& c )
  {
    out << "(" << red << ", " << green << ", " << blue << ")\n";
    return out;
  }
  istream& operator >>(istream& in, color& c)
  {
    in >> red >> green >> blue;
    return in;
  }
};

int main()
{

  char a;
  do{
    color c1, c2;
    cout << "\nWelcome to the color compare program!\n";

    cout << "Enter Color 1: ";
    cin >> c1;

    cout << "Enter Color 2: ";
    cin >> c2;

    if(c1 < c2)
      cout << "Color 1 is less than Color 2\n";
    else
      cout << "Color 1 is NOT less than Color 2\n";
    if(c1 > c2)
      cout << "Color is greater than Color 2\n";
    else
      cout << "Color is greater than Color 2\n";

    cout << "Color 1 + Color 2 = " << c1 + c2;
    cout << "\nColor 1 - Color 2 = " << c1 - c2;

    cout << "\nWould you like to continue (Enter y or n): ";
    cin >> a;
  } while(a == 'y' || a == 'Y');
}
