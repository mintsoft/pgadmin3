//////////////////////////////////////////////////////////////////////////
//
// pgScript - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2008, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
//////////////////////////////////////////////////////////////////////////


#include "pgAdmin3.h"
#include "pgscript/statements/pgsAssertStmt.h"

#include "pgscript/exceptions/pgsAssertException.h"

pgsAssertStmt::pgsAssertStmt(const pgsExpression * cond, pgsThread * app) :
	pgsStmt(app), m_cond(cond)
{

}

pgsAssertStmt::~pgsAssertStmt()
{
	pdelete(m_cond);
}

void pgsAssertStmt::eval(pgsVarMap & vars) const
{
	pgsOperand result = m_cond->eval(vars);
	if (!result->pgs_is_true())
	{
		throw pgsAssertException(m_cond->value());
	}
}
