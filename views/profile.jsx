/**
 * Copyright 2021 Torsten Mehnert
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
/* global getProfileVisits */
import {createElement} from 'complate-stream';
import Layout from "./components/layout";
import Alert from "./components/alert";

// The person also have a "email", try to put some "mailto:" link in here.
// Or make a component for this.
export default function Profile({person}) {
    // Try to change the Alert severity to "warning" and reload your Browser
    return <Layout>
        <h1>Profile</h1>
        <footer class="text-muted mb-3">Viewed {getProfileVisits()} times</footer>
        <Alert severity="info">
            You should change your password in the next few days.
        </Alert>
        <Details person={person}/>
    </Layout>
}

function Details({person}) {
    return <section>
        <dl>
            <dt>Forename</dt>
            <dd>{person.forename}</dd>
            <dt>Lastname</dt>
            <dd>{person.lastname}</dd>
        </dl>
    </section>
}

