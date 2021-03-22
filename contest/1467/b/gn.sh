ls() {
    if [[ $@ == "-la" ]]; then
        command ls -la | more
    else
        command ls "$@"
    fi
}


gn() {
    if[[ $@ == "a" ]]; then
        command cf gen && vim ./a/a.cpp
    fi
}
  

