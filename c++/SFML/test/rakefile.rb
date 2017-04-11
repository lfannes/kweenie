task :run do
	sh'g++ main.cpp -o main -lsfml-window'
	sh'./main'
end