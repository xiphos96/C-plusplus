/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#include <Gwork/Test/TestAPI.h>
#include <Gwork/Controls/RadioButtonController.h>
#include <Gwork/Controls/VerticalSlider.h>
#include <Gwork/Controls/HorizontalSlider.h>

using namespace Gwk;

class Slider : public TestUnit
{
public:

    GWK_CONTROL_INLINE(Slider, TestUnit)
    {
        {
            Gwk::Controls::HorizontalSlider* slider = new Gwk::Controls::HorizontalSlider(this);
            slider->SetPos(10, 10);
            slider->SetSize(150, 20);
            slider->SetRange(0, 100);
            slider->SetFloatValue(25);
            slider->onValueChanged.Add(this, &Slider::SliderMoved);
        }
        {
            Gwk::Controls::HorizontalSlider* slider = new Gwk::Controls::HorizontalSlider(this);
            slider->SetPos(10, 40);
            slider->SetSize(150, 20);
            slider->SetRange(0, 100);
            slider->SetFloatValue(20);
            slider->SetNotchCount(10);
            slider->SetClampToNotches(true);
            slider->onValueChanged.Add(this, &Slider::SliderMoved);
        }
        {
            Gwk::Controls::VerticalSlider* slider = new Gwk::Controls::VerticalSlider(this);
            slider->SetPos(160, 10);
            slider->SetSize(20, 200);
            slider->SetRange(0, 100);
            slider->SetFloatValue(25);
            slider->onValueChanged.Add(this, &Slider::SliderMoved);
        }
        {
            Gwk::Controls::VerticalSlider* slider = new Gwk::Controls::VerticalSlider(this);
            slider->SetPos(190, 10);
            slider->SetSize(20, 200);
            slider->SetRange(0, 100);
            slider->SetFloatValue(20);
            slider->SetNotchCount(10);
            slider->SetClampToNotches(true);
            slider->onValueChanged.Add(this, &Slider::SliderMoved);
        }
    }

    void SliderMoved(Base* control)
    {
        Gwk::Controls::Slider* slider = (Gwk::Controls::Slider*)control;
        OutputToLog(Utility::Format("Slider Value: %.2f", slider->GetFloatValue()));
    }

};


DECLARE_TEST(Slider);
