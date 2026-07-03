use std::io;

const ASH_SPEED: i32 = 1000;
const ASH_ATTACK_RADIOUS: i32 = 2000;
const ZOMBIE_SPEED: i32 = 400;
const ZOMBIE_ATTACK_RADIOUS: i32 = 400;
const MAX_X: i32 = 9000;
const MAX_Y: i32 = 16000;

#[derive(Clone)]
struct Pos {
    x: i32, 
    y: i32,
}

impl Pos {
    fn new() -> Self {
        Self {x: 0, y: 0}
    }

    fn from(x: i32, y: i32) -> Self {
        Self {x, y}
    }

    fn distance(a: &Pos, b: &Pos) -> i32 {
        let x2 = (a.x - b.x) * (a.x - b.x);
        let y2 = (a.y - b.y) * (a.y - b.y);
        
        ((x2 as f32) + (y2 as f32)).sqrt() as i32
    }

    fn next_pos(from: &Pos, to: &Pos, speed: i32) -> Pos {
        if Pos::distance(&from, &to) < speed {
            return to.clone();
        }

        let dx = (to.x - from.x) as f32;
        let dy = (to.y - from.y) as f32;

        let total_distance = (dx * dx + dy * dy).sqrt();
        if total_distance == 0.0 {
            return Pos::from(from.x, from.y);
        }

        let ratio = speed as f32 / total_distance;
        Pos {
            x: (from.x as f32 + dx * ratio) as i32,
            y: (from.y as f32 + dy * ratio) as i32
        }
    }
}

#[derive(Clone)]
struct Person {
    id: usize,
    pos: Pos, 
}

impl Person {
    fn new(id: usize, pos: Pos) -> Self {
        Self {id, pos}
    }

    fn distance_to(&self, other_person: &Person) -> i32 {
        Pos::distance(&self.pos, &other_person.pos)
    }

    fn get_zombie_next_pos(&self, humans: &Vec<Person>, ash_pos: &Pos) -> Pos {
        let nearest_person_pos = humans.iter()
            .min_by_key(|human| self.distance_to(human))
            .map(|human| human.pos.clone());
        
        let target_pos = match (ash_pos.clone(), nearest_person_pos) {
            (a, Some(b)) => {
                if Pos::distance(&a, &self.pos) > Pos::distance(&b, &self.pos) {
                    b
                } else {
                    a
                }
            },
            (a, None) => a,
        };

        Pos::next_pos(&self.pos, &target_pos, ZOMBIE_SPEED)
    }
}

#[derive(Clone)]
struct State {
    ash_pos: Pos,
    zombies: Vec<Person>,
    humans: Vec<Person>,
}

impl State {
    fn new() -> Self {
        Self {
            ash_pos: Pos::new(),
            zombies: Vec::new(),
            humans: Vec::new()
        }
    }


    fn zombie_distance_to_nearest_human(&self, zombie: &Person) -> i32 {
        self.humans.iter()
            .map(|human| zombie.distance_to(human))
            .min()
            .unwrap_or(0)
    }

    fn human_distance_to_nearest_zombie(&self, human: &Person) -> i32 {
        self.zombies.iter()
            .map(|zombie| zombie.distance_to(human))
            .min()
            .unwrap_or(0)
    }

    fn get_zombie_nearest_human(&self) -> &Person {
        self.zombies.iter()
            .min_by_key(|zombie| self.zombie_distance_to_nearest_human(zombie))
            .expect("there is no zombie on the map")
    }

    fn next_state_from_curr(&self, next_ash_pos: &Pos) -> State {
        let mut next_state = self.clone();
        next_state.ash_pos = next_ash_pos.clone();
        
        for zombie in next_state.zombies.iter_mut() {
            zombie.pos = zombie.get_zombie_next_pos(&next_state.humans, &next_state.ash_pos);
        }

        next_state.zombies = next_state.zombies.into_iter()
            .filter(|zombie| Pos::distance(&zombie.pos, &next_state.ash_pos) > ASH_ATTACK_RADIOUS)
            .collect();

        next_state.humans = next_state.humans.into_iter()
            .filter(|human | self.human_distance_to_nearest_zombie(human) < ZOMBIE_ATTACK_RADIOUS)
            .collect();
        
        next_state
    }
}

struct Game {
    current_state: State,
}

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

impl Game {
    fn get_input(&mut self) {
        self.current_state = State::new();

        // x, y
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        self.current_state.ash_pos.x = parse_input!(inputs[0], i32);
        self.current_state.ash_pos.y = parse_input!(inputs[1], i32);

        // human_noumber
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let human_noumber = parse_input!(input_line, usize);
        self.current_state.humans.reserve(human_noumber);

        // humans
        for _ in 0..human_noumber as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let human_id = parse_input!(inputs[0], i32);
            let human_x = parse_input!(inputs[1], i32);
            let human_y = parse_input!(inputs[2], i32);

            let human = Person::new(human_id as usize, Pos::from(human_x, human_y));
            self.current_state.humans.push(human);
        }

        // zombie_noumber
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let zombie_noumber = parse_input!(input_line, usize);
        self.current_state.zombies.reserve(zombie_noumber);

        // zombies
        for _ in 0..zombie_noumber as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let zombie_id = parse_input!(inputs[0], i32);
            let zombie_x = parse_input!(inputs[1], i32);
            let zombie_y = parse_input!(inputs[2], i32);
            let _zombie_x_next = parse_input!(inputs[3], i32);
            let _zombie_y_next = parse_input!(inputs[4], i32);

            let zombie = Person::new(zombie_id as usize, Pos::from(zombie_x, zombie_y));
            self.current_state.zombies.push(zombie);
        }
    }

    fn compute_best_next_ash_pos(&self) -> Pos {
        let zombie_nearest_human = self.current_state.get_zombie_nearest_human();
        let zombie_next_pos = zombie_nearest_human.get_zombie_next_pos(&self.current_state.humans, &self.current_state.ash_pos);
        let next_ash_pos = Pos::next_pos(&self.current_state.ash_pos, &zombie_next_pos, ASH_SPEED);
        let next_state = State::next_state_from_curr(&self.current_state, &next_ash_pos);

        next_ash_pos
    }
}

fn main() {
    let mut game = Game{ current_state: State::new() };
    loop {
        game.get_input();
        let pos = game.compute_best_next_ash_pos();
        println!("{} {}", pos.x, pos.y);
    }
}
