#pragma once
#include "../common.h"
#include <cstdio>
#include <vector>
#include <cassert>

#define ASSERT assert

template <typename T, int N> class Array
{
public:
	enum {_len = N};
	typedef T t_Val;
public:
	T& operator[] (int i)
	{
				ASSERT(i>=0&&i<N);
		return _p[i];
	}
	const T& operator[] (int i) const
	{
				ASSERT(i>=0&&i<N);
		return _p[i];
	}

protected:
	T _p[N];
};

class CSimpleObject
{
public:
	CSimpleObject(void);
	~CSimpleObject(void);

public:
	bool IsLoaded() { return m_pVertexList!=NULL;}

	void Destroy();
	bool LoadFromObj(const char* fn);
	bool SaveToObj(const char* fn);

	bool Parse(FILE* fp);
	bool CheckParse(int nVertices,std::vector<Array<int,3> > & vecTriangles);

	int             m_nVertices;
	int             m_nTriangles;
	Vec3*        m_pVertexList;
	Array<int,3>*   m_pTriangleList;
};
