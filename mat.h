#ifndef MAT_H
#define MAT_H

#include <array>
#include <cstddef>
#include <iostream>

using std::size_t;

template <size_t N, size_t M>
using mat = std::array<std::array<double, M>, N>;

template <size_t N>
mat<N, N> identity()
{
	mat<N, N> res = {};
	for (size_t i = 0; i < N; i++)
	{
		res[i][i] = 1;
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> zeros()
{
	return {};
}

template <size_t N, size_t M>
mat<M, N> trans(const mat<N, M> &a)
{
	mat<M, N> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[j][i] = a[i][j];
		}
	}
	return res;
}

template <size_t N, size_t O, size_t M>
mat<N, M> operator*(const mat<N, O> &a, const mat<O, M> &b)
{
	mat<N, M> res;
	double temp = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			temp = 0;
			for (size_t k = 0; k < O; k++)
			{
				temp += a[i][k] * b[k][j];
			}
			res[i][j] = temp;
		}
	}
	return res;
}

template <size_t N>
double trace(const mat<N, N> &a)
{
	double res = 0;
	for (size_t i = 0; i < N; i++)
	{
		res += a[i][i];
	}
	return res;
}

mat<3, 3> skew(const mat<3, 1> &a)
{
	mat<3, 3> res = {};
	res[0][1] = -a[2][0];
	res[0][2] = a[1][0];
	res[1][0] = a[2][0];
	res[1][2] = -a[0][0];
	res[2][0] = -a[1][0];
	res[2][1] = a[0][0];
	return res;
}

template <size_t N1, size_t N2, size_t M>
mat<N1 + N2, M> cV(const mat<N1, M> &a, const mat<N2, M> &b)
{
	mat<N1 + N2, M> res;
	for (size_t i = 0; i < N1; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j];
		}
	}
	for (size_t i = 0; i < N2; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i + N1][j] = b[i][j];
		}
	}
	return res;
}

template <typename T1, typename... T>
auto cV(T1 a, T... args) -> decltype(cV(a, cV(args...)))
{
	return cV(a, cV(args...));
}

template <size_t N, size_t M1, size_t M2>
mat<N, M1 + M2> cH(const mat<N, M1> &a, const mat<N, M2> &b)
{
	mat<N, M1 + M2> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M1; j++)
		{
			res[i][j] = a[i][j];
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M2; j++)
		{
			res[i][j + M1] = b[i][j];
		}
	}
	return res;
}

template <typename T1, typename... T>
auto cH(T1 a, T... args) -> decltype(cH(a, cH(args...)))
{
	return cH(a, cH(args...));
}

template <size_t N, size_t M>
mat<N, M> kronecker(const mat<N, M> &a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j] * b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator*(float a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a * b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator*(const mat<N, M> &a, float b)
{
	return b * a;
}

template <size_t N, size_t M>
mat<N, M> operator*(double a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a * b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator*(const mat<N, M> &a, double b)
{
	return b * a;
}

template <size_t N, size_t M>
mat<N, M> operator/(float a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a / b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator/(const mat<N, M> &a, float b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j]/b;
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator/(double a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a / b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator/(const mat<N, M> &a, double b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j]/b;
		}
	}
	return res;
}



template <size_t N, size_t M>
mat<N, M> operator+(const mat<N, M> &a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j] + b[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> operator-(const mat<N, M> &a, const mat<N, M> &b)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = a[i][j] - b[i][j];
		}
	}
	return res;
}

template <size_t nS, size_t nE, size_t mS, size_t mE, size_t N, size_t M>
mat<nE - nS, mE - mS> select(const mat<N, M> &a)
{
	mat<nE - nS, mE - mS> res;
	for (size_t i = nS; i < nE; i++)
	{
		for (size_t j = mS; j < mE; j++)
		{
			res[i][j] = a[nS + i][mS + j];
		}
	}
	return res;
}

template <size_t nS, size_t nE, size_t mS, size_t mE, size_t N, size_t M>
mat<nE - nS, mE - mS> sel(const mat<N, M> &a)
{

	return select<nS>;
}

template <size_t N, size_t M>
mat<N, M> operator-(const mat<N, M> &a)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = -a[i][j];
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> tanh(const mat<N, M> &a)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = std::tanh(a[i][j]);
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> abs(const mat<N, M> &a)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = std::abs(a[i][j]);
		}
	}
	return res;
}

template <size_t N, size_t M>
mat<N, M> exp(const mat<N, M> &a)
{
	mat<N, M> res;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = exp(a[i][j]);
		}
	}
	return res;
}


template <size_t N, size_t M>
void print(const mat<N, M> &a)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template <typename CharT, typename Traits, size_t N, size_t M>
std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &ostream, mat<N, M> A)
{
	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			ostream << A[i][j] << ",";
		}
	}
	for (size_t j = 0; j < M - 1; j++)
	{
		ostream << A[N - 1][j] << ",";
	}
	ostream << A[N - 1][M - 1];
	return ostream;
}

/*int main(int argc, char const *argv[])
{
	float eta = 0.5, th = 0.2, k = 0.3, d = 1.3, gamma = 0.9;
	mat<3,1> beta = {0.2,0.1,0.6};
	mat<7,1> y_i  = {0, 1, 0.03, 0.6, 5, 4, 3.1};
	mat<7,1> y_j  = 3*y_i;
	mat<7,1> x_i  = 0.1*y_i;
	mat<6,1> v_y  = {0, 1, 0.03, 0.6, 5, 4};
	auto SS = skew(beta);
	//auto Uminus_xi = cV( trans(mult(-1, beta)) , minus( mult( eta , identity<3> () ), SS ) );
	auto Uminus_xi  = cV(trans(-beta), (eta*identity<3>()) - SS );
	auto PsiT = cV(cH(identity<3>(),  zeros<3,4>() ),
				   cH( zeros<3,3>(),  th*0.5*trans(Uminus_xi)));
	//print(Uminus_xi);
	auto vdot_y = -(k/th)*PsiT*(y_i- x_i) - d*v_y - gamma*PsiT*(y_i-y_j);
	print(vdot_y);
	print(select<0,5,0,1>(vdot_y));
	return 0;
}*/
#endif
