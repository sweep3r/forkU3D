#pragma once

#include <Urho3D/Urho3DAll.h>

class DefaultApp : public Application
{
    URHO3D_OBJECT(DefaultApp, Application);

public:
    explicit DefaultApp(Context* context);
    void Start() override;

private:
    SharedPtr<Scene> scene_;
};
