task :game do
	Dir.chdir('game'){sh 'cook run'}
end

task :oef do 
	sh "g++ oef-4-9.cpp -o oef-4-9"
	sh "./oef-4-9"
end