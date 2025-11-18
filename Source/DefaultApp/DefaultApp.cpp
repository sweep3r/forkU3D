#include "DefaultApp.h"

// U3D macro to define an entry point.
URHO3D_DEFINE_APPLICATION_MAIN(DefaultApp)

// Which will expand to this
// int RunApplication()
// {
//     Urho3D::SharedPtr<Urho3D::Context> context(new Urho3D::Context());
//     Urho3D::SharedPtr<DefaultApp> application(new DefaultApp(context));
//     return application->Run();
// }
// extern "C" __attribute__((visibility("default"))) int SDL_main(int argc, char** argv);
// int SDL_main(int argc, char** argv)
// {
//     Urho3D::ParseArguments(argc, argv);
//     return RunApplication();
// }

DefaultApp::DefaultApp(Context* context) : Application(context)
{
}

// Demo taken from the existing rake file.
void DefaultApp::Start()
{
    auto* cache = GetSubsystem<ResourceCache>();
    auto* graphics = GetSubsystem<Graphics>();
    graphics->SetWindowIcon(cache->GetResource<Image>("Textures/UrhoIcon.png"));
    graphics->SetWindowTitle("DefaultApp");

    scene_ = new Scene(context_);
    scene_->CreateComponent<Octree>();

    Node* objectNode = scene_->CreateChild();
    auto* object = objectNode->CreateComponent<StaticModel>();
    object->SetModel(cache->GetResource<Model>("Models/Mushroom.mdl"));
    object->SetMaterial(cache->GetResource<Material>("Materials/Mushroom.xml"));

    auto* sound = scene_->CreateComponent<SoundSource>();
    sound->SetSoundType(SOUND_MUSIC);
    auto* music = cache->GetResource<Sound>("Music/Ninja Gods.ogg");
    music->SetLooped(true);
    sound->Play(music);

    Node* lightNode = scene_->CreateChild();
    auto* light = lightNode->CreateComponent<Light>();
    light->SetLightType(LIGHT_DIRECTIONAL);
    lightNode->SetDirection(Vector3(0.6f, -1.f, 0.8f));

    Node* cameraNode = scene_->CreateChild();
    auto* camera = cameraNode->CreateComponent<Camera>();
    cameraNode->SetPosition(Vector3(0.f, 0.3f, -3.f));

    GetSubsystem<Renderer>()->SetViewport(0, new Viewport(context_, scene_, camera));

    SubscribeToEvent(E_KEYUP, [&](StringHash, VariantMap&) { engine_->Exit(); });
    SubscribeToEvent(E_UPDATE, [=](StringHash, VariantMap& eventData) {
        objectNode->Yaw(eventData[Update::P_TIMESTEP].GetFloat() * 4.0f);
    });
}
