#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

errors=0

check_push_swap() {
    if [ ! -f "./push_swap" ]; then
        echo -e "${RED}Error: push_swap executable not found${NC}"
        exit 1
    fi
    if [ ! -f "./checker_Mac" ]; then
        echo -e "${RED}Error: checker_Mac executable not found${NC}"
        exit 1
    fi
}

generate_random_sequence() {
    local size=$1
    local numbers=()
    
    for ((i=1; i<=$size; i++)); do
        numbers+=($i)
    done    
    for ((i=$size-1; i>0; i--)); do
        local j=$(($RANDOM % (i+1)))
        local temp=${numbers[i]}
        numbers[i]=${numbers[j]}
        numbers[j]=$temp
    done
    
    echo "${numbers[@]}"
}

# Test 3 numbers
test_three() {
    echo -e "\n${YELLOW}Testing 3 numbers combinations:${NC}"
    local inputs=(
        "1 3 2"
        "2 1 3"
        "2 3 1"
        "3 1 2"
        "3 2 1"
    )

    for input in "${inputs[@]}"; do
        echo -e "\nTest: [$input]"
        local moves=$(./push_swap $input)
        echo "$moves"
        local count=$(echo "$moves" | wc -l | tr -d ' ')
        echo "Operations count: $count"
        
        if [ "$count" -le 3 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}ERROR: More than 3 operations${NC}"
            ((errors++))
        fi
        
        local result=$(echo "$moves" | ./checker_Mac $input)
        if [ "$result" = "OK" ]; then
            echo -e "Checker result: ${GREEN}$result${NC}"
        else
            echo -e "Checker result: ${RED}$result${NC}"
            ((errors++))
        fi
        echo "------------------------"
    done
}

# Test 4 numbers
test_four() {
    echo -e "\n${YELLOW}Testing 4 numbers combinations:${NC}"
    local inputs=(
        "1 2 4 3" "1 3 2 4" "1 3 4 2" "1 4 2 3" "1 4 3 2"
        "2 1 3 4" "2 1 4 3" "2 3 1 4" "2 3 4 1" "2 4 1 3" "2 4 3 1"
        "3 1 2 4" "3 1 4 2" "3 2 1 4" "3 2 4 1" "3 4 1 2" "3 4 2 1"
        "4 1 2 3" "4 1 3 2" "4 2 1 3" "4 2 3 1" "4 3 1 2" "4 3 2 1"
    )

    for input in "${inputs[@]}"; do
        echo -e "\nTest: [$input]"
        local moves=$(./push_swap $input)
        echo "$moves"
        local count=$(echo "$moves" | wc -l | tr -d ' ')
        echo "Operations count: $count"
        
        if [ "$count" -le 12 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}ERROR: More than 12 operations${NC}"
            ((errors++))
        fi
        
        local result=$(echo "$moves" | ./checker_Mac $input)
        if [ "$result" = "OK" ]; then
            echo -e "Checker result: ${GREEN}$result${NC}"
        else
            echo -e "Checker result: ${RED}$result${NC}"
            ((errors++))
        fi
        echo "------------------------"
    done
}

# Test 5 numbers
test_five() {
    echo -e "\n${YELLOW}Testing 5 numbers with random combinations:${NC}"
    for ((i=1; i<=10; i++)); do
        local input=$(generate_random_sequence 5)
        echo -e "\nTest $i: [$input]"
        local moves=$(./push_swap $input)
        echo "$moves"
        local count=$(echo "$moves" | wc -l | tr -d ' ')
        echo "Operations count: $count"
        
        if [ "$count" -le 12 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}ERROR: More than 12 operations${NC}"
            ((errors++))
        fi
        
        local result=$(echo "$moves" | ./checker_Mac $input)
        if [ "$result" = "OK" ]; then
            echo -e "Checker result: ${GREEN}$result${NC}"
        else
            echo -e "Checker result: ${RED}$result${NC}"
            ((errors++))
        fi
        echo "------------------------"
    done
}

# Test 100 numbers
test_hundred() {
    echo -e "\n${YELLOW}Testing 100 numbers:${NC}"
    local input=$VAR2
    echo "Testing random 100 numbers..."
    local moves=$(./push_swap $input)
    local count=$(echo "$moves" | wc -l | tr -d ' ')
    echo "Operations count: $count"
    
    if [ "$count" -le 700 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}ERROR: More than 700 operations${NC}"
        ((errors++))
    fi
    
    local result=$(echo "$moves" | ./checker_Mac $input)
    if [ "$result" = "OK" ]; then
        echo -e "Checker result: ${GREEN}$result${NC}"
    else
        echo -e "Checker result: ${RED}$result${NC}"
        ((errors++))
    fi
}

# Test 500 numbers
test_five_hundred() {
    echo -e "\n${YELLOW}Testing 500 numbers:${NC}"
    local input=$VAR
    echo "Testing random 500 numbers..."
    local moves=$(./push_swap $input)
    local count=$(echo "$moves" | wc -l | tr -d ' ')
    echo "Operations count: $count"
    
    if [ "$count" -le 5500 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}ERROR: More than 5500 operations${NC}"
        ((errors++))
    fi
    
    local result=$(echo "$moves" | ./checker_Mac $input)
    if [ "$result" = "OK" ]; then
        echo -e "Checker result: ${GREEN}$result${NC}"
    else
        echo -e "Checker result: ${RED}$result${NC}"
        ((errors++))
    fi
}

# Test error cases
test_errors() {
    echo -e "\n${YELLOW}Testing error cases:${NC}"
    local error_cases=(
        "1 35 56 3 -"
        "1 35 56 3 '-'4"
        "578 54 8 4 5 87 4 45 2"
        "578 54 8 4 5 87 + 45 2"
        "-3 '3 5' 10"
    )

    for test in "${error_cases[@]}"; do
        echo -e "\nTesting: $test"
        if ./push_swap $test 2>&1 | grep -q "Error"; then
            echo -e "${GREEN}OK - Error detected${NC}"
        else
            echo -e "${RED}ERROR - Should have detected error${NC}"
            ((errors++))
        fi
    done
}

main() {
    check_push_swap
    
    # Run all tests
    test_three
    test_four
    test_five
    test_hundred
    test_five_hundred
    test_errors
    
    echo -e "\n${YELLOW}Test Results:${NC}"
    if [ $errors -eq 0 ]; then
        echo -e "${GREEN}All tests passed successfully!${NC}"
    else
        echo -e "${RED}Failed tests: $errors${NC}"
    fi
}

VAR="212 369 221 498 170 552 589 521 486 82 494 438 298 577 107 203 63 499 528 149 21 465 402 309 489 432 257 451 445 175 50 17 100 329 573 134 189 426 485 497 121 294 19 598 380 215 139 92 148 227 44 146 423 488 315 264 308 416 279 461 403 192 385 393 442 102 242 399 559 224 586 323 318 22 296 64 373 76 352 250 46 222 462 592 25 3 137 295 355 75 338 263 283 7 523 232 161 466 570 533 371 193 88 524 594 512 502 375 476 366 180 414 226 518 272 12 517 459 398 151 487 287 345 285 595 370 544 557 144 463 478 516 78 179 319 475 239 441 553 126 584 510 270 359 477 593 111 116 519 491 585 39 504 61 305 357 372 335 501 349 235 112 539 452 59 56 117 200 456 471 596 422 252 217 482 277 474 347 364 229 547 525 132 360 202 282 413 346 271 395 207 280 29 560 258 548 389 358 153 155 382 185 159 195 379 554 417 65 143 597 136 177 118 448 468 241 415 73 386 546 243 37 362 231 98 51 351 433 401 361 69 405 378 428 562 353 565 79 408 165 167 581 113 532 150 292 57 31 206 443 168 427 299 230 536 142 6 99 33 289 120 290 171 157 322 220 367 342 237 450 187 135 93 458 58 412 2 74 569 267 368 198 169 1 481 219 53 437 572 265 152 104 312 300 534 356 262 95 316 321 23 201 119 24 125 564 260 381 332 509 339 333 496 183 269 503 211 479 32 556 447 561 472 108 540 411 45 421 275 254 162 128 434 467 94 97 407 313 123 326 354 236 535 60 54 376 563 473 470 62 96 327 377 213 404 435 520 85 431 238 530 505 330 600 172 506 526 436 363 307 324 480 543 555 176 317 141 284 551 47 558 396 9 87 164 469 52 208 86 14 10 464 549 529 493 344 34 303 583 580 406 571 131 249 394 186 449 35 490 453 424 196 255 588 550 188 579 311 410 182 83 71 133 457 246 301 160 268 68 216 522 204 154 13 599 328 18 306 281 138 341 538 251 101 0 387 158 66 225 388 16 444 348 191 566 247 41 390 27 15 384 507 156 425 513 184 291 531 276 537 5 320 383 286 199 115 197 574 30 545 259 325 293 343 446 392 304 590 11 67 245 43 391 233 166 205 266 500 114 84"

VAR2="90 95 78 72 50 10 40 26 18 36 34 44 83 19 24 32 46 42 17 81 71 89 60 73 55 93 47 82 88 52 99 92 68 41 63 100 57 61 48 80 96 66 2 59 49 69 7 74 85 1 70 35 8 53 86 64 25 30 75 28 45 43 37 94 54 39 21 27 76 65 3 33 51 31 29 62 6 87 98 15 84 14 9 22 77 11 16 23 97 79 67 12 58 91 5 56 4 38 20 13"

main
