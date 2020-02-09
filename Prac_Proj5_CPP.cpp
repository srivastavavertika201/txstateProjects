Project5: Array of Structure

Name: Susan Varghese Tharakan
Texas State Id: A04988443
Net Id: s_v289

Problem Statement:

a.	Create one arrayof 15+ products including product ID's, unit 
prices, quantities sold, and sales of each product. The products should be defined in a file and input into an array of structure ADT.  

b.	Sort the above data and adding the sales of each product. You may use either bubble sort or selection sort in ascending or descending order on sales. You must have at least one function in the project and the arguments of function call must include array of structure and by passing as address.

c.	Print out product ID's, unit prices, quantities sold, and the sales of each product. Also print out the total units sold and the total sales. 

d.	You should use file to do input/output and print them if needed.

e.	Turn in source programs, and output that should include but not
limited to: original data (array of structures), sorted array, and the total sales and total units sold.













SOURCE CODE

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
struct Product{
	int prodId;
	float prodCost;
	int prodSold;
	float totalProdSales;
}; // Product structure
//Print the product details
void dispProducts(Product* prod_ptr, int size)
{
	int iterator;
	cout<< " Product count\tProduct Id\tUnit Price\tQuantities Sold \tSale of Product\n";
	for (iterator = 0; iterator < size; iterator++)
	{
		prod_ptr->totalProdSales = prod_ptr->prodCost * prod_ptr->prodSold;
		cout<< " "<< iterator + 1 << "\t\t" << prod_ptr->prodId << "\t\t" << prod_ptr->prodCost << "\t\t" << prod_ptr->prodSold << "\t\t\t" << prod_ptr->totalProdSales<<"\n";
		prod_ptr++;
	}
}
//Function to sort the array based on the total sale of individual products
void sortProducts(Product* prod_ptr, int size)
{
	int temp_i, iterator_prod;
	float temp_f, next_f;
	for(iterator_prod = size - 1; iterator_prod > 0; iterator_prod--)
	{
		
		for (int index = 0; index < iterator_prod; index++)
		{
			if (prod_ptr[index].totalProdSales > prod_ptr[index+1].totalProdSales)
			{
				temp_i = prod_ptr[index].prodId;
                                prod_ptr[index].prodId = prod_ptr[index+1].prodId;
                                prod_ptr[index+1].prodId = temp_i;
                                temp_f = prod_ptr[index].prodCost;
                                prod_ptr[index].prodCost = prod_ptr[index+1].prodCost;
                                prod_ptr[index+1].prodCost = temp_f;
                                temp_i = prod_ptr[index].prodSold;
                                prod_ptr[index].prodSold =  prod_ptr[index+1].prodSold;
                                prod_ptr[index+1].prodSold = temp_i;
                                temp_f = prod_ptr[index].totalProdSales;
                                prod_ptr[index].totalProdSales = prod_ptr[index+1].totalProdSales;
                                prod_ptr[index+1].totalProdSales = temp_f;
			}
		}
	}
}	
// Function to calculate the total sale for all products
void totalSale(Product* prod_ptr, float* amount, int size)
{
	for(int iterator_sales = 0; iterator_sales < size; iterator_sales++)
	{
		*amount += prod_ptr->totalProdSales;
		prod_ptr++;		
	}
}
// Function to calculate the total number of units sold
void totalUnitSold(Product* prod_ptr, int* unitsSold ,int size)
{
	for(int iterator_units = 0; iterator_units < size; iterator_units++)
	{
		*unitsSold += prod_ptr->prodSold;
		prod_ptr++;
	}
}
int main()
{
	int pcount = 1,count = 0, status = 0, iterator_sales = 0,iterator = 0,totalUnits = 0, array_size, line_iter, pId, pSold, disp_iter, counter, selection, cID, cCount, order, index, temp_i;
	float pCost, totalAmount = 0.00, cCost, temp_f;
	float* totalAmount_ptr;
	int* totalUnits_ptr;
	totalAmount_ptr = &totalAmount;
	totalUnits_ptr = &totalUnits;
	ofstream prodFile;
	prodFile.open("ProdDets.txt", ofstream :: out); // will be used to write to the file
	while (1) 
	{
		cout<< "\nEnter Product ID, Product Cost and Number of products sold \nNote:: Press 0 if all product details are entered.\n";
		cout<< "Product Id : ";
		cin>> cID;
		if (cID == 0)
                {
                        break;
                }
		cout<< "Product Cost : ";
		cin>> cCost;
		cout<< "Number of Items sold : ";
		cin>> cCount;
		prodFile<<cID<<","<<cCost<<","<<cCount<<";"; // Details are entered into the file
		count++;
	}
	prodFile.close();
	ifstream myFile; 
	string lineCount, line, value;
	myFile.open("ProdDets.txt", ifstream :: binary); // Will be used to open the file
	if (! myFile)	
	{
		cout<< "File does not exist\n";
	}
	cout<< "There are "<< count << " product details entered into the text file\n\n";
	Product* heb = new Product[count];
	Product* heb_ptr = heb;
	while(getline(myFile, line, ';')) // Insert product id, unit cost and product sale into their respective arrays. 
	{
		line_iter = 1;
		stringstream buffer_line;
		buffer_line << line;
		while(getline(buffer_line, value, ','))
		{
			if (line_iter % 2 == 0)
			{
				stringstream value_float;
				value_float << value;
				value_float >> pCost;
				heb[iterator].prodCost = pCost;
			}
			else if (line_iter % 3 == 0)
			{
				stringstream value_int_pn;
				value_int_pn << value;
				value_int_pn >> pSold;
				heb[iterator].prodSold = pSold;
			}
			else 
			{
				stringstream value_int_pid;
				value_int_pid << value;
				value_int_pid >> pId;
				heb[iterator].prodId = pId;
			}
			line_iter++;
		}
		iterator++;
	}
	myFile.close(); // Close text file 
	cout<< "The product details are displayed below: \n"; // Display product details in the text file
	dispProducts(heb,count);
	sortProducts(heb, count); // function to sort the array based on the sale of product
	cout<< "\n\nProduct details displayed below in ascending order\n"; // Display products in the sorted array
	dispProducts(heb,count);
	while (status < 4)
	{
		cout<<"\n\nDo you want to \n1. Find the total sales for all the products\n2. Find the total number of units sold\n3. Exit\nEnter your option below\n";
		cin>> selection;
		if (selection == 1)
		{
			totalSale(heb,&totalAmount,count);
			cout<< "The total sale is $"<< totalAmount << "\n"; // function to calculate the total cost for all products
		}
		else if (selection == 2)
		{
			totalUnitSold(heb, totalUnits_ptr,count);
			cout<< "The total number of units sold - " <<totalUnits<< "\n"; // function to calculate the total units sold
		}
		else if (selection == 3)
		{
			cout<< "Thank You! have a nice day\n";	
			status = 4;
		}
		else
		{
			cout<< "Invalid entry!!! Check again.\n";
			status = 1;
		}
		status ++;
	}	
	delete[] heb;
	return 0;
}		

		
OUTPUT
 
 
 
 

 

INPUT (TEXT FILE - "ProdDets.txt")
 

