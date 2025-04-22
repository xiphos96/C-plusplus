/*
 *  Gwork
 *  Copyright (c) 2011 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */


#pragma once
#ifndef GWK_TEST_TESTAPI_H
#define GWK_TEST_TESTAPI_H

#include <Gwork/Test/Test.h>


class TestAPI : public TestCategory
{
public:
    GWK_CONTROL(TestAPI, TestCategory);

private:

    void OnCategorySelect(Gwk::Event::Info info);

    Gwk::Controls::Base *m_lastControl;

};


#endif // ifndef GWK_TEST_TESTAPI_H
