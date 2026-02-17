#include "Brain.hpp"

std::string Brain::getIdea(int index) const{
		const std::string allIdeas[100] = {
		"find shelter", "is this dangerous",
		"I need to eat", "what is this sound",
		"why is it so hot", "why is it so cold",
		"the food was very good", "the food was bad",
		"I'm sleepy", "I slept well",
		"I'm energetic", "this place is very nice",
		"this place is safe", "this place is not safe",
		"this is very funny", "hello human",
		"hello stranger", "who are you",
		"I want to eat some snacks", "Is it nap time yet?", "I saw a bird today",
		"Why does the human stare at the glowing box?", "I love belly rubs",
		"Must protect the house from the mailman", "Squirrel!", "The red dot is my enemy",
		"I wonder what shoes taste like", "Is that a treat I hear?", "Rain is annoying",
		"I should bark at nothing at 3 AM", "The sofa is a great scratching post",
		"I am the king of this living room", "Why do they take me to the vet?",
		"Ball! Ball! Ball!", "I need to find the perfect spot to sleep",
		"Sniffing grass is very informative", "I hate the vacuum cleaner",
		"Water comes out of the sky sometimes", "I wish I could open the fridge",
		"where am I", "how do I get out of here",
		"is anyone here", "can you help me",
		"what time is it", "where can I find water",
		"is there food nearby", "why is it so dark",
		"is someone there", "can you see that",
		"why is it so quiet", "what should we do now",
		"is this the end", "where can we go",
		"are we alone", "is help coming",
		"why is the light flickering", "did you hear that",
		"why is it so bright", "what happened here",
		"who is there", "can you hear me",
		"is this real", "am I safe",
		"what should I do", "where should I go",
		"is this the right way", "how far is the city",
		"is it going to rain", "why is the ground shaking",
		"what is that smell", "did you see that",
		"is something following me", "can I rest here",
		"is there danger ahead", "why is everyone quiet",
		"where did they go", "is this place abandoned",
		"can I trust you", "what are you doing",
		"why are you staring at me", "is this a dream",
		"how long have I been here", "where is my phone",
		"is there a hospital nearby", "can I sit here",
		"why is it so windy", "what was that noise",
		"is the door locked", "can we leave now",
		"is it morning already", "why is the sky red",
		"is there a way out", "what are we waiting for",
		"is this normal", "why is my heart racing",
		"can you explain this", "is everything okay",
		"where is everyone", "should we hide",
		"The cat/dog is looking at me weirdly"
    };
	return allIdeas[index % 100];
}

Brain::Brain(){
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = Brain::getIdea(std::rand() % 100);
	}
}

Brain::Brain(const Brain& other){
	std::cout << "Brain Copy Constructor called" << std::endl;
	(*this) = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain(){ std::cout << "Brain Destructor called" << std::endl; }
