#include <SFML/Graphics.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

#include <vector>
#include <numeric>

#include "GameObject.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr int WINDOW_FRAMERATE = 120;

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PlatformerEngine");
	window.setFramerateLimit(WINDOW_FRAMERATE);
	
	ImGui::SFML::Init(window);

	sf::Event event{};
	std::shared_ptr<ResourceManager> resources = std::make_shared<ResourceManager>();

	GameObject object(resources);
	ObjectEditor editor(resources);
	
	sf::Clock clock;
	clock.restart();

	std::vector<float> fpsHistory;
	fpsHistory.push_back(0);
	float time = 0;

	while (window.isOpen()) {
		// Update SFML events
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update timer
		sf::Time delta = clock.getElapsedTime();
		float deltaSec = delta.asSeconds();
		time += deltaSec;

		clock.restart();

		// Calculate values for FPS graph
		float fps = 1.f / deltaSec;
		if (fpsHistory.size() > 100) {
			for (size_t i = 1; i < fpsHistory.size(); i++) {
				fpsHistory[i - 1] = fpsHistory[i];
			}
			fpsHistory[fpsHistory.size() - 1] = fps;
		} else {
			fpsHistory.push_back(fps);
		}
		float avgFps = std::accumulate(fpsHistory.begin(), fpsHistory.end(), 0.f) / fpsHistory.size();

		// Update objects
		ImGui::SFML::Update(window, delta);
		object.Update(&editor);

		// Show debug window
		ImGui::Begin("Debug Info");
		ImGui::LabelText("Time", "%.1f sec", time);
		ImGui::LabelText("Delta Time", "%f sec", deltaSec);
		ImGui::LabelText("FPS Limit", "%dfps", WINDOW_FRAMERATE);
		ImGui::LabelText("Avg. FPS", "%.0ffps", avgFps);
		ImGui::PlotLines("FPS Graph", fpsHistory.data(), fpsHistory.size(), 0, "", 0, WINDOW_FRAMERATE, ImVec2(0, WINDOW_FRAMERATE));
		ImGui::End();

		// Redraw scene
		window.clear();
		object.Draw(window);
		ImGui::SFML::Render(window);
		window.display();
	}

	window.close();
	ImGui::SFML::Shutdown();
	return 0;
}