#include "vector.h"

TVector::TVector()
{
	this->n = 0;
	this->x = nullptr;
}

TVector::TVector(int n) {
	this->n = n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = 0.0;
	}
}

TVector::TVector(int n, double* x)
{
	this->n = n;
	this->x = new double[n];
	for (int i = 0; i < n; i++)
	{
		this->x[i] = x[i];
	}
}

TVector::TVector(const TVector& a)
{
	this->n = a.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = a[i];
	}
}

TVector::~TVector()
{
	delete[] x;
}

TVector TVector::operator+(const TVector& a) const
{
	if (this->n != a.n)
	{
		throw std::runtime_error("������ ����� ��������");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] + a[i];
	}
	return res;
}

TVector TVector::operator-(const TVector& a) const
{
	if (this->n != a.n)
	{
		throw std::runtime_error("������ ����� ��������");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] - a[i];
	}
	return res;
}

double TVector::operator*(const TVector& a) const
{
	if (this->n != a.n)
	{
		throw std::runtime_error("������ ����� ��������");
	}
	double res = 0.0;
	for (int i = 0; i < this->n; i++)
	{
		res += this->x[i] * a[i];
	}
	return res;
}

TVector TVector::operator+(const double a) const
{
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] + a;
	}
	return res;
}


TVector TVector::operator-(const double a) const
{
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] - a;
	}
	return res;
}

TVector TVector::operator*(const double a) const
{
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] * a;
	}
	return res;
}

const TVector& TVector::operator=(const TVector& a)
{
	if (this == &a) return *this;
	delete[] this->x;
	this->n = a.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = a[i];
	}
	return *this;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
	std::cout << "������� ����� �������: ";
	in >> v.n;
	std::cout << "������� ���������� ��������: ";
	if (v.x != nullptr) {
		delete[] v.x;
	}
	v.x = new double[v.n];
	for (int i = 0; i < v.n; i++)
	{
		in >> v[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const TVector& v)
{
	out << "������: ";

	for (int i = 0; i < v.n; i++)
	{
		out << v[i] << " ";
	}
	out << std::endl;
	return out;
}

double TVector::operator[](const int idx) const
{
	if (idx >= 0 && idx < this->n)
	{
		return this->x[idx];
	}
	throw std::exception("������ �� ����������");
}

double& TVector::operator[](const int idx)
{
	if (idx >= 0 && idx < this->n)
	{
		return this->x[idx];
	}
	throw std::exception("������ �� ����������");
}

double TVector::Norma_Vectora() const {
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {
		sum += x[i] * x[i];
	}
	return std::sqrt(sum);
}

