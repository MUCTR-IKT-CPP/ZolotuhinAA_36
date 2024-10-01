src-dir := src/
inc-dir := include/

target-dir := target/
incs := $(wildcard $(inc-dir)*.h)
srcs := $(wildcard $(src-dir)*.cpp)
objs := $(patsubst $(src-dir)%.cpp, $(target-dir)%.o, $(srcs))

main-run:
	$(target-dir)main

main: mk-dirs $(objs) $(incs)
	g++ -o $(target-dir)main $(objs) -I $(inc-dir) -Wall
	

$(objs): $(target-dir)%.o: $(src-dir)%.cpp $(incs)
	g++ -o $@ -c $< -I $(inc-dir) -Wall



mk-dirs:
	mkdir -p $(target-dir)
