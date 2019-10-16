#include<Immortal.h>

class FlappyBird : public Immortal::Application
{
public:
	FlappyBird()
	{

	}
	~FlappyBird()
	{

	}
};

Immortal::Application* Immortal::CreateApplication()
{
	return new FlappyBird();
}