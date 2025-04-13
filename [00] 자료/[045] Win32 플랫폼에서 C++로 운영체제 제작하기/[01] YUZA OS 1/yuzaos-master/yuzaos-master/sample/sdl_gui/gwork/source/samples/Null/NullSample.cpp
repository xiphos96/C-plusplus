/*
 *  Gwork Null Sample
 *
 *  /// NOTE: This is a null application just used to make sure that Gwork compiles. ///
 *
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#include <Gwork/Skins/TexturedBase.h>
#include <Gwork/Test/Test.h>
#include <Gwork/Input/Null.h>
#include <Gwork/Renderers/Null.h>
#include <Gwork/Platform.h>

int main(int argc, char** argv)
{
    // Create resource path calculator.
    Gwk::Platform::RelativeToExecutablePaths paths(GWORK_RESOURCE_DIR);
    // Create a Gwork Allegro Renderer
    Gwk::Renderer::Null* renderer = new Gwk::Renderer::Null(paths);

    // Create a Gwork skin
    Gwk::Skin::TexturedBase skin(renderer);
    skin.SetRender(renderer);
    skin.Init("DefaultSkin.png");

    skin.SetDefaultFont("OpenSans.ttf", 11);

    // Create a Canvas (it's root, on which all other Gwork panels are created)
    Gwk::Controls::Canvas *canvas = new Gwk::Controls::Canvas(&skin);
    canvas->SetSize(1024, 768);
    canvas->SetDrawBackground(true);
    canvas->SetBackgroundColor(Gwk::Color(150, 170, 170, 255));

    // Create our unittest control (which is a Window with controls in it)
    auto unit = new TestFrame(canvas);
    unit->SetPos(10, 10);

    Gwk::Input::Null GworkInput;
    GworkInput.Initialize(canvas);

    canvas->RenderCanvas();

    return EXIT_SUCCESS;
}
