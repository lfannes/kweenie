task :run do
	sh"g++ main.cpp -o main"
	sh"./main"
end