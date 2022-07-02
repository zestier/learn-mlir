FROM ubuntu

# Throw in some coding tools
RUN apt-get update && apt-get -y install git cmake ninja-build

# Preinstall Clang and such because it supposedly builds MLIR faster
RUN apt-get update && apt-get -y install clang lld lldb

# Build MLIR
ENV LLVM_SOURCE_DIR=/usr/local/src/llvm-project
ENV LLVM_BUILD_DIR=/usr/local/src/llvm-project/build
RUN git clone --depth 1 https://github.com/llvm/llvm-project.git $LLVM_SOURCE_DIR
RUN cmake -G Ninja -B $LLVM_BUILD_DIR $LLVM_SOURCE_DIR/llvm                      \
   -DLLVM_ENABLE_PROJECTS="llvm;mlir"                                            \
   -DCMAKE_BUILD_TYPE=RelWithDebInfo                                             \
   -DLLVM_ENABLE_ASSERTIONS=ON                                                   \
   -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DLLVM_ENABLE_LLD=ON    \
   -DLLVM_INSTALL_UTILS=ON
RUN cmake --build $LLVM_BUILD_DIR --target check-mlir install

# Add in zsh because I like it better
RUN apt-get update && apt-get -y install zsh
RUN echo "PROMPT='%~%# '" >> ~/.zshrc
RUN chsh -s `which zsh`

CMD ["zsh"]